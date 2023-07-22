#include "../../include/minishell.h"

t_tree_node	*parser(t_words *word_list, t_data *data)
{
	t_tree_node	*root;

	root = create_tree(word_list);
	if (check_syntax_err_tree(root))
	{
		data->err_number = 1;
		return (free_all_tree_node(root));
	}
	return (root);
}
