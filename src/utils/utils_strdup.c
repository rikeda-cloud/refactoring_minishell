/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_strdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:02:58 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/06 15:02:59 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*strdup_n(const char *src, size_t n)
{
	size_t	idx;
	char	*dest;

	if (src == NULL)
		return (NULL);
	idx = 0;
	dest = (char *)ft_calloc(sizeof(char), (n + 1));
	if (dest == NULL)
		return (NULL);
	while (idx < n)
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (dest);
}

char	*strdup_env(const char *str, bool *err_flag)
{
	const char	*env_position;
	char		*env;

	if (str == NULL)
		return (NULL);
	env_position = get_env_position(str);
	if (*env_position == '\0')
		return (NULL);
	env = strdup_n(&env_position[1], count_env_size(env_position));
	if (env == NULL)
		return (reverse_flag(err_flag));
	return (env);
}
