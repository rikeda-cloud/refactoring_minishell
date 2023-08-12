/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_assignment_pattern.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:59:24 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/12 12:52:03 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static bool	is_assignment_cmd(const char *str)
{
	if (str == NULL)
		return (false);
	else if (ft_strcmp(str, "export") == 0)
		return (true);
	else
		return (false);
}

bool	is_assignment_pattern(t_tree_node *node)
{
	t_words	*word_list;

	word_list = node->word_list;
	while (word_list != NULL)
	{
		if (is_redirect(word_list->token_type) && word_list->next != NULL)
			word_list = word_list->next;
		else if (is_assignment_cmd(word_list->word))
			return (true);
		else
			return (false);
		word_list = word_list->next;
	}
	return (false);
}
