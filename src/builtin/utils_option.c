#include "../../include/minishell.h"

bool	is_option(const char *str, int option_c)
{
	if (*str != '-')
		return (false);
	str++;
	while (*str != '\0')
	{
		if (*str++ != option_c)
			return (false);
	}
	return (true);
}

bool	is_option_n(const char *str)
{
	if (is_option(str, 'n'))
		return (true);
	return (false);
}

t_words	*get_not_option_node(t_words *word_list)
{
	while (word_list != NULL)
	{
		if (is_option_n(word_list->word))
			word_list = word_list->next;
		else
			return (word_list);
	}
	return (NULL);
}
