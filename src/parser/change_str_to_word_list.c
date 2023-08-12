/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_str_to_word_list.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:00:55 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/12 12:52:51 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static const char	*skip_space_char(const char *str)
{
	while (is_space(*str))
		str++;
	return (str);
}

t_words	*change_str_to_word_list(const char *str, t_data *data)
{
	t_words	*word_list;

	word_list = NULL;
	while (*str != '\0')
	{
		str = skip_space_char(str);
		if (*str == '\0')
			break ;
		word_list = append_str_to_word_list(word_list, str);
		if (word_list == NULL)
			return (reverse_flag(&data->err_flag));
		str = &str[count_word_size(str)];
	}
	return (word_list);
}
