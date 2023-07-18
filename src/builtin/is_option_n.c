#include "../../include/minishell.h"

bool	is_option(char *str, int option_c)
{
	if (*str != '-')
		return (false);
	str++;
	while (*str != '\0')
	{
		if (*str != option_c)
			return (false);
		str++;
	}
	return (true);
}

bool	is_option_n(t_words *word_list)
{
	while (word_list != NULL)
	{
		if (is_option(word_list->word, 'n'))
			return (true);
		word_list = word_list->next;
	}
	return (false);
}
