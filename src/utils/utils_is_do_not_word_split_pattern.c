#include "../../include/minishell.h"

bool	is_in_equal(const char *str)
{
	if (str == NULL)
		return (false);
	while (*str != '\0')
	{
		if (*str++ == '=')
			return (true);
	}
	return (false);
}

static bool	is_in_dallor_front_of_equal(const char *str)
{
	while (*str != '\0' && *str != '=')
	{
		if (*str++ == '$')
			return (true);
	}
	return (false);
}

bool	is_do_not_word_split_pattern(bool flag, const char *str)
{
	if (flag == false)
		return (false);
	else if (is_in_equal(str) == false)
		return (false);
	else if (is_in_dallor_front_of_equal(str))
		return (false);
	else
		return (true);
}
