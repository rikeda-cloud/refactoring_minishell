#include "../../include/minishell.h"

t_words	*del_word(t_words *word)
{
	t_words	*next_word;

	next_word = word->next;
	free(word->word);
	free(word);
	return (next_word);
}

