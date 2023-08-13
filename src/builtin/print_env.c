/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:57:33 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/13 14:15:49 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	print_env(void (*fmt)(char *, char *, int), t_env *env, int fd)
{
	fmt(env->name, env->value, fd);
}

static void	print_upper(t_env *env, void (*fmt)(char *, char *, int), int fd)
{
	while (env != NULL)
	{
		if (ft_islower(*env->name))
			break ;
		print_env(fmt, env, fd);
		env = env->next;
	}
}

static void	print_lower(t_env *env, void (*fmt)(char *, char *, int), int fd)
{
	while (env != NULL)
	{
		if (ft_isupper(*env->name) == 0)
			print_env(fmt, env, fd);
		env = env->next;
	}
}

void	print_all_env(void (*fmt)(char *, char *, int), int fd, t_data *data)
{
	size_t	hash_number;

	if (data->env_map == NULL)
		return ;
	hash_number = 1;
	while (hash_number < HASH_MAP_SIZE)
		print_upper(data->env_map[hash_number++], fmt, fd);
	hash_number = 0;
	while (hash_number < HASH_MAP_SIZE)
		print_lower(data->env_map[hash_number++], fmt, fd);
}
