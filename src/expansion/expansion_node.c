/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:59:17 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/12 12:52:01 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static t_words	*expansion_word(char *word, t_data *data, bool split_flag)
{
	t_words	*word_list;

	word_list = split_str_by_quote(word);
	if (word_list == NULL)
		return (reverse_flag(&data->err_flag));
	word_list = split_word_list_by_dallor_str(word_list, data);
	if (data->err_flag)
		return (NULL);
	delete_last_dallor(word_list, data);
	if (data->err_flag)
		return (free_all_word_list(word_list));
	variable_expansion(word_list, data);
	if (data->err_flag)
		return (free_all_word_list(word_list));
	word_split(word_list, data, split_flag);
	if (data->err_flag)
		return (free_all_word_list(word_list));
	word_list = trim_quote_and_cat(word_list, &data->err_flag);
	if (data->err_flag)
		return (NULL);
	return (word_list);
}

t_words	*expansion_node(t_tree_node *node, bool assign_flag, t_data *data)
{
	t_words	*word_list;

	if (is_redirect(node->word_list->token_type))
	{
		word_list = new_redirect_node(node->word_list->token_type);
		if (word_list == NULL)
		{
			data->err_flag = true;
			return (NULL);
		}
		return (word_list);
	}
	else if (is_do_word_split_pattern(assign_flag, node->word_list->word))
		return (expansion_word(node->word_list->word, data, true));
	else
		return (expansion_word(node->word_list->word, data, false));
}

t_words	*expansion_heredoc_node(t_tree_node *node, bool *err_flag)
{
	t_words	*heredoc;
	t_words	*delimiter;

	heredoc = new_redirect_node(node->word_list->token_type);
	if (heredoc == NULL)
		return (reverse_flag(err_flag));
	if (node->word_list->next == NULL)
		return (heredoc);
	delimiter = split_str_by_quote(node->word_list->next->word);
	if (delimiter == NULL)
	{
		reverse_flag(err_flag);
		return (free_word_node(heredoc));
	}
	delimiter = trim_quote_and_cat(delimiter, err_flag);
	if (*err_flag)
		return (free_word_node(heredoc));
	delimiter->token_type = get_delimiter_type(node->word_list->next->word);
	heredoc->next = delimiter;
	return (heredoc);
}
