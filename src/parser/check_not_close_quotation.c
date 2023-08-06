/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_not_close_quotation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:00:57 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/06 16:34:51 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static bool	is_not_close_quotation(const char *str)
{
	bool	quote_flag;
	int		quote_char;

	quote_flag = false;
	while (*str != '\0')
	{
		if (is_quotation(*str) && quote_flag == false)
		{
			reverse_flag(&quote_flag);
			quote_char = *str;
		}
		else if (quote_flag && quote_char == *str)
			reverse_flag(&quote_flag);
		str++;
	}
	return (quote_flag);
}

bool	check_not_close_quotation(const t_words *word_list)
{
	while (word_list != NULL)
	{
		if (is_not_close_quotation(word_list->word))
			return (print_err1(ERR_NOT_CLOSE_QUOTATION));
		word_list = word_list->next;
	}
	return (false);
}
