#include "../../include/minishell.h"

bool	is_token_type_quotation(t_token_type type)
{
	if (type == TMP_SINGLE_QUOTE)
		return (true);
	if (type == TMP_DOUBLE_QUOTE)
		return (true);
	return (false);
}

bool	is_type_in_word_list(t_words *word_list, t_token_type word_type)
{
	while (word_list != NULL)
	{
		if (word_list->token_type == word_type)
			return (true);
		word_list = word_list->next;
	}
	return (false);
}
