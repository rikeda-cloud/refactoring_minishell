/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_or_update_env.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:58:03 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/06 15:37:07 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	insert_or_update_env(char *word, t_data *data)
{
	char	*env_name;
	char	*env_value;
	t_env	*env;

	env_name = strdup_n(word, count_to_front_of_c(word, '='));
	if (env_name == NULL)
		return ;
	env = select_env(data->env_map, env_name);
	if (env == NULL)
		insert_env_to_env_map(data->env_map, ft_strdup(word));
	else
	{
		while (*word != '\0' && *word != '=')
			word++;
		if (*word++ != '\0')
		{
			env_value = strdup_n(word, count_to_front_of_c(word, '\0'));
			if (env_value != NULL)
				update_env(data->env_map, env_name, env_value);
			free_str(env_value);
		}
	}
	free_str(env_name);
}
