/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_wait.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:58:19 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/06 17:12:31 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	do_waitpid(pid_t pid, int *wstatus, int mode)
{
	if (waitpid(pid, wstatus, mode) == -1)
		perror_exit("waitpid", 1);
}

static int	change_wstatus_to_err_code(int wstatus)
{
	if (WIFEXITED(wstatus))
		return (WEXITSTATUS(wstatus));
	else if (WIFSIGNALED(wstatus))
		return (128 + WTERMSIG(wstatus));
	else
		return (WEXITSTATUS(wstatus));
}

void	child_wait(t_tree_node *first_cmd, t_table *table, t_data *data)
{
	int			wstatus;
	t_tree_node	*cmd;
	size_t		idx;

	cmd = first_cmd;
	idx = 0;
	while (true)
	{
		if (is_last_cmd(cmd))
		{
			do_waitpid(table[idx++].pid, &wstatus, 0);
			data->err_code = change_wstatus_to_err_code(wstatus);
			if (g_sig_mode == EXEC_C_MODE && WIFSIGNALED(wstatus))
				print_core_dumped(wstatus);
			break ;
		}
		else
			do_waitpid(table[idx++].pid, NULL, 0);
		if (cmd == first_cmd)
			cmd = cmd->prev->right;
		else
			cmd = cmd->prev->prev->right;
	}
}
