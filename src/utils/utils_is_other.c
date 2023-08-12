/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_is_other.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:02:41 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/12 12:53:32 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

bool	is_c_in_str(const char *str, int c)
{
	if (str == NULL)
		return (false);
	while (*str != '\0')
	{
		if (*str++ == c)
			return (true);
	}
	return (false);
}

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
