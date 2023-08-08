/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:01:08 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/06 15:01:09 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_words	*lexer(const char *str, t_data *data)
{
	t_words	*word_list;

	word_list = change_str_to_word_list(str, data);
	if (word_list == NULL)
	{
		if (data->err_flag)
			data->err_code = 1;
		return (NULL);
	}
	add_words_type(word_list);
	if (check_not_close_quotation(word_list))
	{
		data->err_code = 1;
		word_list = free_all_word_list(word_list);
	}
	else if (check_syntax_err_word_list(word_list, data))
	{
		data->err_code = 1;
		word_list = free_all_word_list(word_list);
	}
	return (word_list);
}
