/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_err_tree.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:01:00 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/12 12:52:52 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static bool	is_syntax_err(t_words *word_list, t_words *next_word, t_data *data)
{
	t_words	*prev_word;

	prev_word = word_list;
	if (word_list == NULL)
		return (false);
	word_list = word_list->next;
	while (word_list != NULL)
	{
		if (is_redirect(prev_word->token_type))
		{
			if (is_redirect(word_list->token_type))
				return (err_syntax(word_list->word, &data->err_code));
		}
		prev_word = word_list;
		word_list = word_list->next;
	}
	if (is_redirect(prev_word->token_type) && next_word)
		return (err_syntax(next_word->word, &data->err_code));
	else if (is_redirect(prev_word->token_type) && !next_word)
		return (err_syntax("newline", &data->err_code));
	return (false);
}

bool	check_syntax_err_tree(t_tree_node *node, t_data *data)
{
	node = get_leftmost_node(node);
	if (node->prev == NULL)
		return (is_syntax_err(node->word_list, NULL, data));
	if (is_syntax_err(node->word_list, node->prev->word_list, data))
		return (true);
	node = node->prev->right;
	while (node->prev->prev != NULL)
	{
		if (is_syntax_err(node->word_list, node->prev->word_list, data))
			return (true);
		node = node->prev->prev->right;
	}
	return (is_syntax_err(node->word_list, NULL, data));
}
