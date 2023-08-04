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

int do_cmd(t_tree_node *root, int prevfd, int heredocfd, t_data *data)
{
    pid_t   pid;
    int     pipefd[2];

    pipe(pipefd);
    pid = fork();
    if (pid == 0)
    {
		dup2_and_close_1(prevfd);
		dup2_and_close_2(pipefd);
		dup2_and_close_1(heredocfd);
        redirect_check(root->word_list, data);
        root->word_list = delete_redirect_node(root->word_list);
		if (is_builtin_cmd(root->word_list->word))
			exec_builtin_cmd_child_proc(root->word_list, data);
		else
			exec_normal_cmd_child_proc(root->word_list, data);
    }
    return (parents(root->word_list, pid, prevfd, pipefd));
}

void    do_lst_cmd(t_tree_node *root, int prevfd, int heredocfd, t_data *data)
{
    pid_t   pid;

    pid = fork();
    if (pid == 0)
    {
		dup2_and_close_1(prevfd);
		dup2_and_close_1(heredocfd);
        redirect_check(root->word_list, data);
        root->word_list = delete_redirect_node(root->word_list);
		if (is_builtin_cmd(root->word_list->word))
			exec_builtin_cmd_child_proc(root->word_list, data);
		else
			exec_normal_cmd_child_proc(root->word_list, data);
    }
    else
        last_parents(root->word_list, pid, prevfd);
}

void	do_normal_cmd(t_tree_node *root, int prevfd, int *table, t_data *data)
{
	t_tree_node	*first_cmd;

	first_cmd = root;
	while(true)
	{
		if (is_last_cmd(root))
		{
			do_lst_cmd(root, prevfd, *table++, data);
			break ;
		}
		prevfd = do_cmd(root, prevfd, *table++, data);
		if (root == first_cmd)
			root = root->prev->right;
		else
			root = root->prev->prev->right;
	}
	child_wait(root, first_cmd, data);
}

