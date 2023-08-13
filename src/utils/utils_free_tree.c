/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free_tree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:02:20 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/13 14:18:14 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	recursive_free_tree_node(t_tree_node *node)
{
	t_tree_node	*left;
	t_tree_node	*right;

	if (node != NULL)
	{
		left = node->left;
		right = node->right;
		free_all_word_list(node->word_list);
		free(node);
		recursive_free_tree_node(left);
		recursive_free_tree_node(right);
	}
}

void	*free_all_tree_node(t_tree_node *root)
{
	recursive_free_tree_node(root);
	return (NULL);
}
