/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:58:30 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/12 12:41:45 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	parent(int prevfd, int *pipefd, t_data *data)
{
	if (prevfd != 0)
		do_close(prevfd, false, &data->err_flag);
	do_close(pipefd[1], false, &data->err_flag);
	return (pipefd[0]);
}

static void	last_parent(t_table *table, pid_t pid, int prevfd, t_data *data)
{
	table->pid = pid;
	if (prevfd != 0)
		do_close(prevfd, false, &data->err_flag);
}

int	do_cmd(t_tree_node *root, int prevfd, t_table *table, t_data *data)
{
	pid_t	pid;
	int		pipefd[2];

	do_pipe(pipefd);
	pid = do_fork();
	if (pid == 0)
	{
		dup2_and_close_stdin(prevfd, true, NULL);
		dup2_and_close_pipefd(pipefd, true, NULL);
		dup2_and_close_stdin(table->fd, true, NULL);
		redirect_check(root->word_list, true);
		root->word_list = delete_redirect_node(root->word_list);
		if (root->word_list == NULL)
			exit(0);
		else if (is_builtin_cmd(root->word_list->word))
			exec_builtin_cmd_child_proc(root->word_list, data);
		else
			exec_normal_cmd_child_proc(root->word_list, data);
	}
	table->pid = pid;
	return (parent(prevfd, pipefd, data));
}

void	do_lst_cmd(t_tree_node *root, int prevfd, t_table *table, t_data *data)
{
	pid_t	pid;

	pid = do_fork();
	if (pid == 0)
	{
		dup2_and_close_stdin(prevfd, true, NULL);
		dup2_and_close_stdin(table->fd, true, NULL);
		redirect_check(root->word_list, true);
		root->word_list = delete_redirect_node(root->word_list);
		if (root->word_list == NULL)
			exit(0);
		else if (is_builtin_cmd(root->word_list->word))
			exec_builtin_cmd_child_proc(root->word_list, data);
		else
			exec_normal_cmd_child_proc(root->word_list, data);
	}
	else
		last_parent(table, pid, prevfd, data);
}
