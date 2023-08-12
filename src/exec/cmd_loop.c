/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:58:22 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/06 15:59:25 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	cmd_loop(t_tree_node *root, t_data *data)
{
	int		prevfd;
	t_table	*table;

	prevfd = 0;
	root = get_leftmost_node(root);
	table = heredoc_loop(root, data);
	if (table == NULL)
	{
		if (g_sig_mode == HEREDOC_C_MODE)
			data->err_code = 130;
		else
			data->err_code = 1;
		return ;
	}
	g_sig_mode = EXEC_MODE;
	signal(SIGQUIT, sig_quit_handler);
	if (is_builtin_cmd_alone_without_env(root))
		do_builtin_cmd_alone_without_env(root, data);
	else
		do_normal_cmd(root, prevfd, table, data);
	free_table(table);
	signal(SIGQUIT, SIG_IGN);
}
