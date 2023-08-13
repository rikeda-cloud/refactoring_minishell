/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:02:55 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/13 14:18:22 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_words	*new_word_node(const char *str)
{
	t_words	*word_list;

	word_list = (t_words *)ft_calloc(sizeof(t_words), 1);
	if (word_list == NULL)
		return (NULL);
	if (str == NULL)
		return (word_list);
	word_list->word = strdup_n(str, count_word_size(str));
	if (word_list->word == NULL)
		return (free_word_node(word_list));
	return (word_list);
}

t_words	*new_word_node_n(const char *str, size_t n, bool flag)
{
	t_words	*new_word;

	new_word = (t_words *)ft_calloc(sizeof(t_words), 1);
	if (new_word == NULL)
		return (NULL);
	new_word->word = strdup_n(str, n);
	if (new_word->word == NULL)
		return (free_word_node(new_word));
	if (flag)
		new_word->token_type = get_quote_type((*str));
	return (new_word);
}

t_words	*new_redirect_node(t_token_type type)
{
	t_words	*heredoc_node;

	heredoc_node = ft_calloc(sizeof(t_words), 1);
	if (heredoc_node == NULL)
		return (NULL);
	if (type == HEREDOC)
		heredoc_node->word = ft_strdup("<<");
	else if (type == READ)
		heredoc_node->word = ft_strdup("<");
	else if (type == WRITE)
		heredoc_node->word = ft_strdup(">");
	else if (type == APPEND)
		heredoc_node->word = ft_strdup(">>");
	if (heredoc_node->word == NULL)
		return (free_word_node(heredoc_node));
	heredoc_node->token_type = type;
	return (heredoc_node);
}

t_words	*new_ifs_node(void)
{
	t_words	*new_ifs_word;

	new_ifs_word = (t_words *)ft_calloc(sizeof(t_words), 1);
	if (new_ifs_word == NULL)
		return (NULL);
	new_ifs_word->token_type = TMP_IFS;
	return (new_ifs_word);
}

t_words	*new_null_node_and_free_words(t_words *words, bool *err_flag)
{
	t_words	*new_words;

	free_all_word_list(words);
	new_words = new_word_node(NULL);
	if (new_words == NULL)
		*err_flag = true;
	return (new_words);
}
