#include "../../include/minishell.h"

t_words	*lexical_analysis(char *str)
{
	t_words	*words;

	words = change_str_to_words(str);
	if (words == NULL)
		return (NULL);
	add_word_type(words);
	return (words);
}
