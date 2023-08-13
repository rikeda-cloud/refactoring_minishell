/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_plus_equal_to_word.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:34:26 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/13 14:15:42 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static size_t	count_to_front_of_plus_equal(const char *str)
{
	size_t	size;

	size = 0;
	if (str == NULL)
		return (0);
	while (str[size] != '\0' && str[size + 1] != '\0')
	{
		if (ft_strncmp(&str[size], "+=", 2) == 0)
			return (size);
		size++;
	}
	return (size);
}

static void	fill_new_word(char *new_str, char *str, char *key, char *value)
{
	size_t	idx;

	idx = 0;
	while (key[idx] != '\0')
	{
		new_str[idx] = key[idx];
		idx++;
	}
	str = &str[idx] + 2;
	new_str[idx++] = '=';
	if (value != NULL)
	{
		while (*value != '\0')
			new_str[idx++] = *value++;
	}
	while (*str != '\0')
		new_str[idx++] = *str++;
}

bool	is_in_plus_equal(const char *str)
{
	if (str == NULL)
		return (false);
	while (str[0] != '\0' && str[1] != '\0')
	{
		if (ft_strncmp(str++, "+=", 2) == 0)
			return (true);
	}
	return (false);
}

char	*skip_plus_equal(char *str)
{
	if (str == NULL)
		return (NULL);
	while (str[0] != '\0' && str[1] != '\0')
	{
		if (ft_strncmp(str, "+=", 2) == 0)
			break ;
		str++;
	}
	return (&str[2]);
}

char	*change_plus_equal_to_word(char *str, t_data *data)
{
	size_t	size;
	t_env	*env;
	char	*key;
	char	*new_str;

	size = ft_strlen(str) - 1;
	key = strdup_n(str, count_to_front_of_plus_equal(str));
	if (key == NULL)
		return (free_str(str));
	env = select_env(data->env_map, key);
	if (env != NULL && env->value != NULL)
		size += ft_strlen(env->value);
	new_str = ft_calloc(sizeof(char), (size + 1));
	if (new_str == NULL)
		return (free_double_str(key, str));
	if (env != NULL && env->value != NULL)
		fill_new_word(new_str, str, key, env->value);
	else
		fill_new_word(new_str, str, key, NULL);
	free_double_str(str, key);
	return (new_str);
}
