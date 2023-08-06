/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free_word_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:02:23 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/06 15:02:24 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	*free_str(char *str)
{
	if (str != NULL)
		free(str);
	return (NULL);
}

void	*free_double_str(char *str1, char *str2)
{
	free_str(str1);
	free_str(str2);
	return (NULL);
}

void	*free_word_node(t_words *word_node)
{
	if (word_node != NULL && word_node->word != NULL)
		free_str(word_node->word);
	if (word_node != NULL)
		free(word_node);
	return (NULL);
}

void	*free_all_word_list(t_words *word_list)
{
	t_words	*tmp;

	while (word_list != NULL)
	{
		tmp = word_list;
		word_list = word_list->next;
		free_word_node(tmp);
	}
	return (NULL);
}

t_words	*free_word_node_get_next_node(t_words *word_node)
{
	t_words	*next_node;

	if (word_node == NULL)
		return (NULL);
	next_node = word_node->next;
	free_word_node(word_node);
	return (next_node);
}
