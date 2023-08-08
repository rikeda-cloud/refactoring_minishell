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
