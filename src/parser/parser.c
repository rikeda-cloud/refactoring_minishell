#include "../../include/minishell.h"

t_tree_node	*parser(t_words *word_list)
{
	t_tree_node	*root;

	root = create_tree(word_list);
	if (check_syntax_err_tree(root))
	{
		/* data.cmd_line = ft_strjoin(data.cmd_line, here_doc_str); */
		root = free_all_tree_node(root);
	}
	return (root);
}
