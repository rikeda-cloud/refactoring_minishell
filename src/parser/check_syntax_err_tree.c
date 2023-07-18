#include "../../include/minishell.h"

static bool	is_syntax_err_word_list(t_words *word_list, t_words *ctrl_operator)
{
	t_words	*prev_word;

	prev_word = word_list;
	if (word_list != NULL)
		word_list = word_list->next;
	while (word_list!= NULL)
	{
		if (is_redirect(prev_word->token_type))
		{
			if (is_redirect(word_list->token_type))
				return (print_fmt_err_syntax(word_list->word));
		}
		prev_word = word_list;
		word_list = word_list->next;
	}
	if (is_redirect(prev_word->token_type) && ctrl_operator != NULL)
		return (print_fmt_err_syntax(ctrl_operator->word));
	else if (is_redirect(prev_word->token_type) && ctrl_operator == NULL)
		return (print_fmt_err_syntax("newline"));
	return (false);
}

bool	check_syntax_err_tree(t_tree_node *node)
{
	node = get_leftmost_node(node);
	if (node->prev == NULL)
		return (is_syntax_err_word_list(node->word_list, NULL));
	if (is_syntax_err_word_list(node->word_list, node->prev->word_list))
		return (true);
	node = node->prev->right;
	while (node->prev->prev != NULL)
	{
		if (is_syntax_err_word_list(node->word_list, node->prev->word_list))
			return (true);
		node = node->prev->prev->right;
	}
	return (is_syntax_err_word_list(node->word_list, NULL));
}
