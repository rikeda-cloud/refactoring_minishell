#include "../../include/minishell.h"

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

bool	is_not_a_valid_identifier(const char *str)
{
	if (!ft_isalpha(*str) && *str != '_')
		return (true);
	str++;
	while (*str != '\0' && *str != '=' && *str != '+')
	{
		if (ft_isalnum(*str) || *str == '_')
			str++;
		else
		return (true);
	}
	if (str[0] == '+' && str[1] != '=')
		return (true);
	return (false);
}
