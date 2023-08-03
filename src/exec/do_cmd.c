#include "../../include/minishell.h"

static int parents(t_words *word_list, pid_t pid, int prevfd, int *pipefd)
{
    word_list->command_pid = pid;
	if (prevfd != 0)
		close(prevfd);
    close(pipefd[1]);
    return(pipefd[0]);
}

static void    last_parents(t_words *word_list, pid_t pid, int prevfd)
{
    word_list->command_pid = pid;
	if (prevfd != 0)
		close(prevfd);
}

static int change_wstatus_to_err_code(int wstatus)
{
	if (WIFEXITED(wstatus))
		return (WEXITSTATUS(wstatus));
	else
		return (128 + WTERMSIG(wstatus));
}

void    child_wait(t_tree_node *root, t_tree_node *first_cmd, t_data *data)
{
	int	wstatus;

    root = first_cmd;
    while(true)
    {
		if (root->prev == NULL || (root->prev->prev == NULL && root != root->prev->left))
        {
			waitpid(root->word_list->command_pid, &wstatus, 0);
			data->err_code = change_wstatus_to_err_code(wstatus);
			break ;
        }
		else
			waitpid(root->word_list->command_pid, NULL, 0); 
		if (root == first_cmd)
            root = root->prev->right;
		else
            root = root->prev->prev->right;
    }
}

int do_cmd(t_tree_node *root, int prevfd, int heredocfd, t_data *data)
{
    pid_t   pid;
    char    **separgv;
    char    **my_environ;
    char    *path;
    int     pipefd[2];

    pipe(pipefd);
    pid = fork();
    if (pid == 0)
    {
        if (prevfd != 0)
        {
            dup2(prevfd, 0);
            close (prevfd);
        }
        close(pipefd[0]);
        dup2(pipefd[1], 1);
        close(pipefd[1]);
        if (heredocfd != 0)
        {
            dup2(heredocfd, 0);
            close(heredocfd);
        }
        redirect_check(root -> word_list, data);
        root->word_list = delete_redirect_node(root->word_list);
		if (is_builtin_cmd(root->word_list->word))
		{
			do_builtin_cmd(root->word_list, data);
			/* free_all_data(data); */
			exit(data->err_code);
		}
		else
		{
	        separgv = change_word_list_to_cmd(root->word_list);
			path = get_path(separgv[0], data);
			my_environ = change_map_to_environ(data->env_map);
			execve(path, separgv, my_environ);
		}
    }
    return (parents(root->word_list, pid, prevfd, pipefd));
}

void    do_lst_cmd(t_tree_node *root, int prevfd, int heredocfd, t_data *data)
{
    pid_t   pid;
    char    **separgv;
	char	**my_environ;
    char    *path;

    pid = fork();
    if (pid == 0)
    {
        if (prevfd != 0)
        {
            dup2(prevfd, 0);
            close (prevfd);
        }
        if (heredocfd != 0)
        {
            dup2(heredocfd, 0);
            close(heredocfd);
        }
        redirect_check(root->word_list, data);
        root->word_list = delete_redirect_node(root->word_list);
		if (is_builtin_cmd(root->word_list->word))
		{
			do_builtin_cmd(root->word_list, data);
			/* free_all_data(data); */
			exit(data->err_code);
		}
		else
		{
			separgv = change_word_list_to_cmd(root->word_list);
			path = get_path(separgv[0], data);
			my_environ = change_map_to_environ(data->env_map);
			execve(path, separgv, my_environ);
		}
    }
    else
        last_parents(root->word_list, pid, prevfd);
}
