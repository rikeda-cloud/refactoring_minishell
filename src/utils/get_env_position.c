/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_position.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:01:19 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/13 14:17:53 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static bool	is_deal_target(const char *str)
{
	if (str[0] != '$')
		return (false);
	else if (ft_isalpha(str[1]) || str[1] == '_' || str[1] == '?')
		return (true);
	else
		return (false);
}

static const char	*skip_to_next_quote_or_dallor_prev_char(const char *str)
{
	str++;
	while (*str != '\0')
	{
		if (is_quotation(*str) || *str == '$')
			break ;
		str++;
	}
	str--;
	return (str);
}

const char	*get_env_position_ignore_quote(const char *str)
{
	while (*str != '\0')
	{
		if (*str == '$')
		{
			if (is_deal_target(str))
				break ;
		}
		str++;
	}
	return (str);
}

const char	*get_env_position(const char *str)
{
	bool	single_quote_flag;
	bool	double_quote_flag;

	single_quote_flag = false;
	double_quote_flag = false;
	while (*str != '\0')
	{
		if (*str == '\'')
			reverse_flag(&single_quote_flag);
		else if (*str == '"')
			reverse_flag(&double_quote_flag);
		else if (*str == '$')
		{
			if (double_quote_flag == true && is_deal_target(str))
				break ;
			if (single_quote_flag == false && is_deal_target(str))
				break ;
			str = skip_to_next_quote_or_dallor_prev_char(str);
		}
		str++;
	}
	return (str);
}
