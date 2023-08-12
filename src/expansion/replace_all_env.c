/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_all_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 12:49:24 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/12 12:52:05 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*new_new_word_ignore(char *str, char *target, const char *new_word)
{
	size_t		new_str_size;
	char		*new_str;
	const char	*env_position;

	new_str_size = ft_strlen(str) + ft_strlen(new_word) - ft_strlen(target);
	new_str = (char *)ft_calloc(sizeof(char), (new_str_size));
	if (new_str == NULL)
		return (NULL);
	env_position = get_env_position_ignore_quote(str);
	ft_strlcat(new_str, str, (env_position - str + 1));
	ft_strcat(new_str, new_word);
	env_position += (ft_strlen(target) + 1);
	ft_strcat(new_str, env_position);
	return (new_str);
}

static char	*replace_ignore(char *str, char *target, const char *new_word)
{
	char	*new_str;

	new_str = new_new_word_ignore(str, target, new_word);
	free_str(str);
	free_str(target);
	return (new_str);
}

static char	*replace_dallor_ignore_quote(char *word, char *target, t_data *d)
{
	t_env	*env;
	char	*str_err_code;
	char	*new_str;

	env = select_env(d->env_map, target);
	new_str = NULL;
	if (*target == '?')
	{
		str_err_code = ft_itoa(d->err_code);
		if (str_err_code != NULL)
			new_str = replace_ignore(word, target, str_err_code);
		else
			free_double_str(word, target);
		free_str(str_err_code);
	}
	else if (env == NULL)
		new_str = replace_ignore(word, target, "");
	else
		new_str = replace_ignore(word, target, env->value);
	if (new_str == NULL)
		d->err_flag = true;
	return (new_str);
}

char	*replace_all_env(char *line, t_token_type type, t_data *data)
{
	char	*target;

	if (type == DELIMITER_QUOTE)
		return (line);
	target = strdup_env_ignore_quote(line, &data->err_flag);
	while (target != NULL && data->err_flag == false)
	{
		line = replace_dallor_ignore_quote(line, target, data);
		target = strdup_env_ignore_quote(line, &data->err_flag);
	}
	if (data->err_flag)
		return (free_str(line));
	return (line);
}
