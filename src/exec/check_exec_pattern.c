#include "../../include/minishell.h"

bool	is_builtin_cmd_alone_without_env(t_tree_node *node)
{
	t_words	*word_list;

	node = get_leftmost_node(node);
	word_list = node->word_list;
	while (word_list != NULL)
	{
		if (is_redirect(word_list->token_type))
			word_list = word_list->next->next;
		else if (is_builtin_cmd(word_list->word) && node->prev == NULL)
		{
			if (ft_strcmp(word_list->word, "env") != 0)
				return (true);
			else
				return (false);
		}
		else
			return (false);
	}
	return (false);
}
