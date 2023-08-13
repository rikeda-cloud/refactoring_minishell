/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_count_map_size.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:47:09 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/13 14:18:09 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static size_t	count_hash_list_size(t_env *hash_list)
{
	size_t	size;

	size = 0;
	while (hash_list != NULL)
	{
		if (hash_list->value != NULL)
			size++;
		hash_list = hash_list->next;
	}
	return (size);
}

size_t	count_map_size(t_env **map)
{
	size_t	idx;
	size_t	size;

	idx = 0;
	size = 0;
	while (idx < HASH_MAP_SIZE)
		size += count_hash_list_size(map[idx++]);
	return (size);
}
