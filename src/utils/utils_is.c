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

bool	is_special_char(const int c)
{
	size_t	idx;

	idx = 0;
	while (SPECIAL_CHAR[idx] != '\0')
	{
		if (SPECIAL_CHAR[idx++] == c)
			return (true);
	}
	return (false);
}

bool	is_quotation(const int c)
{
	if (c == '\'')
		return (true);
	else if (c == '"')
		return (true);
	else
		return (false);
}

bool	is_redirect(const t_token_type type)
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
