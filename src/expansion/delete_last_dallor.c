/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_last_dallor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:59:11 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/13 14:17:00 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static bool	is_last_dallor(const char *str)
{
	size_t	size;

	size = 0;
	while (str[size] != '\0')
		size++;
	if (size == 0)
		return (false);
	else if (str[size - 1] == '$')
		return (true);
	else
		return (false);
}

static char	*trim_last_dallor(char *str)
{
	char	*new_str;
	size_t	str_size;
	size_t	idx;

	str_size = ft_strlen(str);
	new_str = (char *)ft_calloc(sizeof(char), str_size);
	if (new_str == NULL)
		return (free_str(str));
	idx = 0;
	while (idx < (str_size - 1))
	{
		new_str[idx] = str[idx];
		idx++;
	}
	free_str(str);
	return (new_str);
}

void	delete_last_dallor(t_words *words, t_data *data)
{
	int	quote_mode;

	quote_mode = NOT_Q_MODE;
	while (data->err_flag == false && words != NULL && words->next != NULL)
	{
		if (is_token_type_quotation(words->token_type))
			change_quote_mode(&quote_mode, words->token_type);
		else if (quote_mode == NOT_Q_MODE && is_last_dallor(words->word))
		{
			if (is_token_type_quotation(words->next->token_type))
			{
				words->word = trim_last_dallor(words->word);
				if (words->word == NULL)
					data->err_flag = true;
			}
		}
		words = words->next;
	}
}
