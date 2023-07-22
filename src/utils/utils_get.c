#include "../../include/minishell.h"

t_tree_node		*get_leftmost_node(t_tree_node *node)
{
	while (node->left != NULL)
		node = node->left;
	return (node);
}

t_token_type get_quote_type(int c)
{
	if (c == '\'')
		return (TMP_SINGLE_QUOTE);
	else
		return (TMP_DOUBLE_QUOTE);
}

t_token_type	get_delimiter_type(const char *str)
{
	while (*str != '\0')
	{
		if (is_quotation(*str++))
			return (DELIMITER_QUOTE);
	}
	return (DELIMITER);
}

t_words		*get_next_start_word(t_words *words)
{
	while (words != NULL && words->token_type != TMP_IFS)
		words = words->next;
	if (words == NULL)
		return (NULL);
	else
		words = words->next;
	return (words);
}