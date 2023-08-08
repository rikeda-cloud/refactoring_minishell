/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_word_list_by_ifs.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:59:33 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/06 15:41:48 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static t_words	*new_ifs_and_second_node(char *second_word)
{
	t_words	*ifs_and_second;

	if (second_word == NULL)
		return (NULL);
	ifs_and_second = new_ifs_node();
	if (ifs_and_second == NULL)
		return (free_str(second_word));
	if (is_only_space(second_word))
	{
		free_str(second_word);
		return (ifs_and_second);
	}
	ifs_and_second->next = (t_words *)ft_calloc(sizeof(t_words), 1);
	if (ifs_and_second->next == NULL)
	{
		free_word_node(ifs_and_second);
		return (free_str(second_word));
	}
	ifs_and_second->next->word = second_word;
	ifs_and_second->next->token_type = TMP_DALLOR_WORD;
	return (ifs_and_second);
}

static t_words	*new_ifs_node_to_top(t_words *word_node, t_data *data)
{
	t_words	*new_word_list;
	char	*new_str;

	new_str = ft_strdup(&word_node->word[strlen_ifs(word_node->word, data)]);
	if (new_str == NULL)
	{
		data->err_flag = true;
		return (free_all_word_list(word_node));
	}
	new_word_list = ft_calloc(sizeof(t_words), 1);
	if (new_word_list == NULL)
	{
		data->err_flag = true;
		free_str(new_str);
		return (free_all_word_list(word_node));
	}
	word_node->token_type = TMP_IFS;
	word_node->word = free_str(word_node->word);
	new_word_list->token_type = TMP_DALLOR_WORD;
	new_word_list->word = new_str;
	new_word_list->next = word_node->next;
	word_node->next = new_word_list;
	return (word_node);
}

static t_words	*split_word_list_by_ifs(t_words *word, t_data *data)
{
	size_t	idx;
	char	*str;
	t_words	*ifs_and_second;

	if (strlen_ifs(word->word, data) != 0)
		return (new_ifs_node_to_top(word, data));
	str = strdup_n(word->word, strlen_to_ifs(word->word, data));
	if (str == NULL)
		return (free_all_word_list(word));
	idx = strlen_to_ifs(word->word, data);
	idx += strlen_ifs(&word->word[idx], data);
	ifs_and_second = new_ifs_and_second_node(ft_strdup(&word->word[idx]));
	if (ifs_and_second == NULL)
	{
		free_all_word_list(word);
		return (free_str(str));
	}
	ifs_and_second = append_word_node(ifs_and_second, word->next);
	free_str(word->word);
	word->word = str;
	word->next = ifs_and_second;
	return (word);
}

static void	word_split_by_ifs(t_words *word_list, t_data *data, bool flag)
{
	int		q_mode;

	q_mode = NOT_Q_MODE;
	while (word_list != NULL)
	{
		if (is_token_type_quotation(word_list->token_type))
			change_quote_mode(&q_mode, word_list->token_type);
		else if (q_mode == NOT_Q_MODE && is_in_ifs_char(word_list->word, data))
		{
			if (word_list->token_type == TMP_DALLOR_WORD && flag)
				word_list = split_word_list_by_ifs(word_list, data);
			if (word_list == NULL)
			{
				data->err_flag = true;
				break ;
			}
		}
		word_list = word_list->next;
	}
}

void	word_split(t_words *word_list, t_data *data, bool flag)
{
	t_env	*env_ifs;

	env_ifs = select_env(data->env_map, "IFS");
	if (env_ifs == NULL || env_ifs->value == NULL)
		word_split_by_ifs(word_list, data, flag);
	else if (env_ifs->value[0] == '\0')
		return ;
	else
		word_split_by_ifs(word_list, data, flag);
}
