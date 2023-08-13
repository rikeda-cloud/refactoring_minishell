/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_str_by_quote.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:59:36 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/13 14:17:08 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static bool	set_quote_char(int *quote_char, int c)
{
	if (*quote_char == '\0')
		*quote_char = c;
	else
		*quote_char = '\0';
	return (true);
}

static bool	is_need_split(int q_char, int c)
{
	if (is_quotation(c) && q_char == '\0')
		return (true);
	if (is_quotation(c) && q_char == c)
		return (true);
	else
		return (false);
}

static bool	append_word(t_words **words, char *str, size_t size, bool flag)
{
	t_words	*tmp_words;

	if (size == 0)
		return (false);
	else if (*words == NULL)
	{
		*words = new_word_node_n(str, size, flag);
		if (*words == NULL)
			return (true);
	}
	else
	{
		tmp_words = *words;
		while (tmp_words->next != NULL)
			tmp_words = tmp_words->next;
		tmp_words->next = new_word_node_n(str, size, flag);
		if (tmp_words->next == NULL)
		{
			free_word_node(*words);
			return (true);
		}
	}
	return (false);
}

static void	init_vars(int *q_char, char **save, char **str, t_words **new_word)
{
	*q_char = '\0';
	*save = *str;
	*new_word = NULL;
}

t_words	*split_str_by_quote(char *str)
{
	int		q_char;
	char	*save;
	t_words	*new_word;

	init_vars(&q_char, &save, &str, &new_word);
	while (*str != '\0')
	{
		if (is_need_split(q_char, *str) && set_quote_char(&q_char, *str))
		{
			if (append_word(&new_word, save, str - save, false))
				return (NULL);
			if (append_word(&new_word, str, 1, true))
				return (NULL);
			save = str;
			save++;
		}
		str++;
	}
	if (append_word(&new_word, save, str - save, false))
		return (NULL);
	return (new_word);
}
