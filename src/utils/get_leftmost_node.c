#include "../../include/minishell.h"

t_tree_node		*get_leftmost_node(t_tree_node *node)
{
	while (node->left != NULL)
		node = node->left;
	return (node);
}
