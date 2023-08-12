/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:58:05 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/12 12:51:06 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_env	*select_env(t_env **map, const char *env_name)
{
	t_env	*env_list;

	if (map == NULL || env_name == NULL)
		return (NULL);
	env_list = map[hash(*env_name)];
	while (env_list != NULL)
	{
		if (ft_strcmp(env_name, env_list->name) == 0)
			return (env_list);
		env_list = env_list->next;
	}
	return (NULL);
}
