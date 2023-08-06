/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_err_words.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:01:02 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/06 15:01:03 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	check_syntax_err_words(const t_words *word_list, t_data *data)
{
	const t_words	*prev_word;

	prev_word = word_list;
	word_list = word_list->next;
	if (prev_word->token_type == PIPE_CHAR)
		return (err_syntax(prev_word->word, &data->err_code));
	while (word_list != NULL)
	{
		if (prev_word->token_type == PIPE_CHAR)
		{
			if (word_list->token_type == PIPE_CHAR)
				return (err_syntax(prev_word->word, &data->err_code));
		}
		prev_word = word_list;
		word_list = word_list->next;
	}
	if (prev_word->token_type == PIPE_CHAR)
		return (err_syntax(prev_word->word, &data->err_code));
	return (false);
}
