/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_redirect_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:58:25 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/06 14:58:26 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_words	*delete_redirect_node(t_words *word_list)
{
	t_words	*new_word_list;
	t_words	*tmp;

	new_word_list = NULL;
	while (word_list != NULL)
	{
		if (is_redirect(word_list->token_type))
		{
			word_list = free_word_node_get_next_node(word_list);
			word_list = free_word_node_get_next_node(word_list);
		}
		else
		{
			tmp = word_list;
			word_list = word_list->next;
			tmp->next = NULL;
			new_word_list = append_word_node(new_word_list, tmp);
		}
	}
	return (new_word_list);
}
