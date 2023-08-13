/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_consider_cdpath.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:14:21 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/13 14:15:53 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static bool	is_in_double_colon(const char *str)
{
	if (str == NULL)
		return (false);
	while (str[0] != '\0' && str[1] != '\0')
	{
		if (str[0] == ':' && str[1] == ':')
			return (true);
		str++;
	}
	return (false);
}

static void	fill_cdpath(char *new_str, const char *old_str)
{
	size_t	idx;

	idx = 0;
	if (old_str[0] == ':')
		new_str[idx++] = '.';
	else
	{
		while (old_str[0] != ':' || old_str[1] != ':')
			new_str[idx++] = *old_str++;
		new_str[idx++] = *old_str++;
		new_str[idx++] = '.';
	}
	while (*old_str != '\0')
		new_str[idx++] = *old_str++;
}

char	**split_consider_cdpath(const char *str)
{
	char	*new_str;
	char	**cdpath;

	if (str[0] != ':' && is_in_double_colon(str) == false)
		return (ft_split(str, ':'));
	new_str = (char *)ft_calloc(sizeof(char), ft_strlen(str) + 2);
	if (new_str == NULL)
		return (NULL);
	fill_cdpath(new_str, str);
	cdpath = ft_split(new_str, ':');
	free_str(new_str);
	return (cdpath);
}
