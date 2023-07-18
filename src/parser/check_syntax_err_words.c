#include "../../include/minishell.h"

bool	check_syntax_err_words(t_words *word_list)
{
	t_words	*prev_word;

	prev_word = word_list;
	word_list = word_list->next;
	if (prev_word->token_type == PIPE_CHAR)
		return (print_fmt_err_syntax(prev_word->word));
	while (word_list != NULL)
	{
		if (prev_word->token_type == PIPE_CHAR)
		{
			if (word_list->token_type == PIPE_CHAR)
				return (print_fmt_err_syntax(prev_word->word));
		}
		prev_word = word_list;
		word_list = word_list->next;
	}
	if (prev_word->token_type == PIPE_CHAR)
		return (print_fmt_err_syntax(prev_word->word));
	return (false);
}
