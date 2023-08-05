#include "../../include/minishell.h"

static int parents(t_table *table, pid_t pid, int prevfd, int *pipefd)
{
	table->pid = pid;
	if (prevfd != 0)
		close(prevfd);
    close(pipefd[1]);
    return(pipefd[0]);
}

static void    last_parents(t_table *table, pid_t pid, int prevfd)
{
	table->pid = pid;
	if (prevfd != 0)
		close(prevfd);
}

int do_cmd(t_tree_node *root, int prevfd, t_table *table, t_data *data)
{
    pid_t   pid;
    int     pipefd[2];

    pipe(pipefd);
    pid = fork();
    if (pid == 0)
    {
		dup2_and_close_stdin_fileno(prevfd);
		dup2_and_close_pipefd(pipefd);
		dup2_and_close_stdin_fileno(table->fd);
        redirect_check(root->word_list, data);
        root->word_list = delete_redirect_node(root->word_list);
		if (root->word_list == NULL)
			exit(0);
		else if (is_builtin_cmd(root->word_list->word))
			exec_builtin_cmd_child_proc(root->word_list, data);
		else
			exec_normal_cmd_child_proc(root->word_list, data);
    }
    return (parents(table, pid, prevfd, pipefd));
}

void    do_lst_cmd(t_tree_node *root, int prevfd, t_table *table, t_data *data)
{
    pid_t   pid;

    pid = fork();
    if (pid == 0)
    {
		dup2_and_close_stdin_fileno(prevfd);
		dup2_and_close_stdin_fileno(table->fd);
        redirect_check(root->word_list, data);
        root->word_list = delete_redirect_node(root->word_list);
		if (root->word_list == NULL)
			exit(0);
		else if (is_builtin_cmd(root->word_list->word))
			exec_builtin_cmd_child_proc(root->word_list, data);
		else
			exec_normal_cmd_child_proc(root->word_list, data);
    }
    else
        last_parents(table, pid, prevfd);
}

void	do_normal_cmd(t_tree_node *root, int prevfd, t_table *table, t_data *data)
{
	t_tree_node	*first_cmd;
	size_t		idx;

	first_cmd = root;
	idx = 0;
	while(true)
	{
		if (is_last_cmd(root))
		{
			do_lst_cmd(root, prevfd, &table[idx++], data);
			break ;
		}
		prevfd = do_cmd(root, prevfd, &table[idx++], data);
		if (root == first_cmd)
			root = root->prev->right;
		else
			root = root->prev->prev->right;
	}
	child_wait(first_cmd, table, data);
}
