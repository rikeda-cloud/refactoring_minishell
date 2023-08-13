/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_normal_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 12:42:46 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/13 14:16:17 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	do_normal_cmd(t_tree_node *root, int pre, t_table *table, t_data *data)
{
	t_tree_node	*first_cmd;
	size_t		idx;

	first_cmd = root;
	idx = 0;
	while (true)
	{
		if (is_last_cmd(root))
		{
			do_lst_cmd(root, pre, &table[idx++], data);
			break ;
		}
		pre = do_cmd(root, pre, &table[idx++], data);
		if (root == first_cmd)
			root = root->prev->right;
		else
			root = root->prev->prev->right;
	}
	child_wait(first_cmd, table, data);
}
