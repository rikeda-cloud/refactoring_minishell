/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:58:08 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/13 14:16:05 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*new_new_original(const char *name, const char *value)
{
	size_t	size;
	size_t	idx;
	char	*new_original;

	size = ft_strlen(name) + ft_strlen(value) + 1;
	new_original = (char *)ft_calloc(sizeof(char), (size + 1));
	if (new_original == NULL)
		return (NULL);
	idx = 0;
	while (*name != '\0')
		new_original[idx++] = *name++;
	new_original[idx++] = '=';
	while (value != NULL && *value != '\0')
		new_original[idx++] = *value++;
	return (new_original);
}

bool	update_env(t_env **map, const char *name, const char *new_value)
{
	t_env	*target_env;
	char	*tmp_new_original;
	char	*tmp_new_value;

	if (map == NULL)
		return (false);
	target_env = select_env(map, name);
	if (target_env == NULL)
		return (true);
	tmp_new_original = new_new_original(name, new_value);
	tmp_new_value = ft_strdup(new_value);
	if (tmp_new_original == NULL || new_value == NULL)
	{
		free_double_str(tmp_new_original, tmp_new_value);
		return (false);
	}
	target_env->original = free_str(target_env->original);
	target_env->value = free_str(target_env->value);
	target_env->original = tmp_new_original;
	target_env->value = tmp_new_value;
	return (true);
}
