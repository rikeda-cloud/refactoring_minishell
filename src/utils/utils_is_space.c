#include "../../include/minishell.h"

bool	is_space(const int c)
{
	size_t	idx;

	idx = 0;
	while (SPACE_CHAR[idx] != '\0')
	{
		if (SPACE_CHAR[idx++] == c)
			return (true);
	}
	return (false);
}

bool	is_only_space(const char *str)
{
	while (*str != '\0')
	{
		if (is_space(*str++) == false)
			return (false);
	}
	return (true);
}
