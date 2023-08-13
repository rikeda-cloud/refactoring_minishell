/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:01:44 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/13 14:18:11 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	*free_char_array(char **char_list)
{
	size_t	idx;

	if (char_list == NULL)
		return (NULL);
	idx = 0;
	while (char_list[idx] != NULL)
		free_str(char_list[idx++]);
	free(char_list);
	return (NULL);
}

void	*free_table(t_table *table)
{
	if (table != NULL)
		free(table);
	return (NULL);
}

void	*free_all_data(t_data *data)
{
	if (data == NULL)
		return (NULL);
	free_str(data->crr_dir);
	free_hash_map(data->env_map);
	return (NULL);
}
