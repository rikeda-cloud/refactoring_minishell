/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:57:57 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/12 12:51:03 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static t_env	*del_top_env(t_env *env_list)
{
	return (free_env_node_and_get_next_node(env_list));
}

static void	del_middle_env(t_env *env_list, const char *env_name)
{
	t_env	*prev_env;

	prev_env = env_list;
	env_list = env_list->next;
	while (env_list != NULL)
	{
		if (ft_strcmp(env_list->name, env_name) == 0)
		{
			prev_env->next = free_env_node_and_get_next_node(env_list);
			break ;
		}
		prev_env = env_list;
		env_list = env_list->next;
	}
}

bool	delete_env(t_env **map, const char *env_name)
{
	int	hash_value;

	if (map == NULL || select_env(map, env_name) == NULL)
		return (false);
	hash_value = hash(*env_name);
	if (ft_strcmp(map[hash_value]->name, env_name) == 0)
		map[hash_value] = del_top_env(map[hash_value]);
	else
		del_middle_env(map[hash_value], env_name);
	return (true);
}
