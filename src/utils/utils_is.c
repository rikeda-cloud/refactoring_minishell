#include "../../include/minishell.h"

bool	is_space(int c)
{
	size_t	idx;

	idx = 0;
	while (SPACE_CHAR[idx] != '\0')
	{
		if (SPACE_CHAR[idx] == c)
			return (true);
		idx++;
	}
	return (false);
}

bool	is_space_word(char *str)
{
	if (str[0] != '\0' && is_space(str[0]) && str[1] == '\0')
		return (true);
	else
		return (false);
}

bool	is_special_char(int c)
{
	size_t	idx;

	idx = 0;
	while (SPECIAL_CHAR[idx] != '\0')
	{
		if (SPECIAL_CHAR[idx] == c)
			return (true);
		idx++;
	}
	return (false);
}

bool	is_quotation(int c)
{
	if (c == '\'')
		return (true);
	else if (c == '"')
		return (true);
	else
		return (false);
}

bool	is_only_quotation(char *word)
{
	int	quotation;

	if (is_quotation(*word))
		quotation = *word;
	else
		return (false);
	if (word[0] != '\0' && word[1] == quotation && word[2] == '\0')
		return (true);
	else
		return (false);
}
