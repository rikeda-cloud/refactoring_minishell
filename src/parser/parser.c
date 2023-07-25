#include "../../include/minishell.h"

t_tree_node	*parser(t_words *word_list, t_data *data)
{
	t_tree_node	*root;

	root = create_tree(word_list, data);
	if (data->err_flag)
		return (NULL);
	else if (check_syntax_err_tree(root, data))
	{
		data->err_flag = true;
		apparently_heredoc(root);
		return (free_all_tree_node(root));
	}
	else
		return (root);
}
