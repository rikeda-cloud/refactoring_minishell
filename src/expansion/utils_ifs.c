/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ifs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:59:41 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/12 12:52:10 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static bool	is_ifs(int c, t_data *data)
{
	const char	*ifs_chars;
	t_env		*env_ifs;

	env_ifs = select_env(data->env_map, "IFS");
	if (env_ifs != NULL)
		ifs_chars = env_ifs->value;
	else
		ifs_chars = IFS_CHARS;
	while (*ifs_chars != '\0')
	{
		if (*ifs_chars++ == c)
			return (true);
	}
	return (false);
}

bool	is_in_ifs_char(const char *str, t_data *data)
{
	if (str == NULL)
		return (false);
	while (*str != '\0')
	{
		if (is_ifs(*str++, data))
			return (true);
	}
	return (false);
}

size_t	strlen_ifs(const char *str, t_data *data)
{
	size_t	size;

	size = 0;
	while (str[size] != '\0' && is_ifs(str[size], data))
		size++;
	return (size);
}

size_t	strlen_to_ifs(const char *str, t_data *data)
{
	size_t	size;

	size = 0;
	while (str[size] != '\0' && is_ifs(str[size], data) == false)
		size++;
	return (size);
}
