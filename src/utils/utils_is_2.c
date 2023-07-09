#include "../../include/minishell.h"

static bool	print_syntax_error(char *unexpected_token)
{
	printf(SYNTAX_ERR_MES, unexpected_token);
	return (true);
}

bool	is_redirect(t_token_type type)
{
	if (type == WRITE)
		return (true);
	else if (type == READ)
		return (true);
	else if (type == APPEND)
		return (true);
	else if (type == HEREDOC)
		return (true);
	else
		return (false);
}

static bool	is_syntax_error_word_list(t_words *word_list, t_words *prev_word)
{
	t_words	*prev_node;

	prev_node = word_list;
	if (word_list->token_type != END)
		word_list = word_list->next;
	while (word_list->word != NULL && word_list->token_type != END)
	{
		if (is_redirect(prev_node->token_type) && is_redirect(word_list->token_type))
			return (print_syntax_error(word_list->word));
		prev_node = word_list;
		word_list = word_list->next;
	}
	if (is_redirect(prev_node->token_type) && prev_word != NULL)
		return (print_syntax_error(prev_word->word));
	else if (is_redirect(prev_node->token_type) && prev_word == NULL)
		return (print_syntax_error("newline"));
	return (false);
}

bool	is_syntax_error_tree(t_tree_node *node)
{
	while (node->left != NULL)
		node = node->left;
	if (node->prev == NULL)
		return (is_syntax_error_word_list(node->word_list, NULL));
	if (is_syntax_error_word_list(node->word_list, node->prev->word_list))
		return (true);
	node = node->prev->right;
	while (node->prev->prev != NULL)
	{
		if (is_syntax_error_word_list(node->word_list, node->prev->word_list))
			return (true);
		node = node->prev->prev->right;
	}
	return (is_syntax_error_word_list(node->word_list, NULL));
}

bool	is_syntax_error_words(t_words *words)
{
	t_words	*prev_word;

	prev_word = words;
	words = words->next;
	if (prev_word->token_type == PIPE)
		return (print_syntax_error(prev_word->word));
	while (words != NULL && words->token_type != END)
	{
		if (prev_word->token_type == PIPE && words->token_type == PIPE)
			return (print_syntax_error(prev_word->word));
		prev_word = words;
		words = words->next;
	}
	if (prev_word->token_type == PIPE)
		return (print_syntax_error(prev_word->word));
	return (false);
}
