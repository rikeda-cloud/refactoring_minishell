#include "../../include/minishell.h"

t_tree_node	*parser(const char *str, t_data *data)
{
	t_words		*word_list;
	t_tree_node	*root;

	word_list = lexer(str, data);
	if (word_list == NULL)
		return (NULL);
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
