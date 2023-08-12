/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_is_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:02:47 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/12 12:53:34 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (str == NULL)
		return (false);
	while (*str != '\0')
	{
		if (is_space(*str++) == false)
			return (false);
	}
	return (true);
}
