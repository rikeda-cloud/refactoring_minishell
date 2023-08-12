/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free_hash_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:01:47 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/12 12:53:26 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	*free_env(t_env *env)
{
	if (env == NULL)
		return (NULL);
	env->name = free_str(env->name);
	env->value = free_str(env->value);
	env->original = free_str(env->original);
	free(env);
	return (NULL);
}

t_env	*free_env_node_and_get_next_node(t_env *env)
{
	t_env	*next_node;

	if (env == NULL)
		return (NULL);
	next_node = env->next;
	free_env(env);
	return (next_node);
}

static void	*free_hash_list(t_env *hash_list)
{
	t_env	*tmp;

	while (hash_list != NULL)
	{
		tmp = hash_list;
		hash_list = hash_list->next;
		free_env(tmp);
	}
	return (NULL);
}

void	*free_hash_map(t_env **hash_map)
{
	size_t	idx;

	if (hash_map == NULL)
		return (NULL);
	idx = 0;
	while (idx < HASH_MAP_SIZE)
		free_hash_list(hash_map[idx++]);
	free(hash_map);
	return (NULL);
}
