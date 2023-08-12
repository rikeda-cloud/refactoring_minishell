/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_is_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:02:50 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/12 12:53:35 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	is_token_type_quotation(t_token_type type)
{
	if (type == TMP_SINGLE_QUOTE)
		return (true);
	if (type == TMP_DOUBLE_QUOTE)
		return (true);
	return (false);
}

bool	is_type_in_word_list(t_words *word_list, t_token_type type)
{
	while (word_list != NULL)
	{
		if (word_list->token_type == type)
			return (true);
		word_list = word_list->next;
	}
	return (false);
}
