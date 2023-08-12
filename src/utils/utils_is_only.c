/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_is_only.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:02:37 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/12 12:53:31 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	is_only_null_char_node(t_words *word_list)
{
	while (word_list != NULL)
	{
		if (word_list->token_type != TMP_IFS && word_list->word[0] != '\0')
			return (false);
		word_list = word_list->next;
	}
	return (true);
}

bool	is_only_under_env(const char *str)
{
	if (str == NULL)
		return (false);
	if (ft_strncmp(str, "_=", 2) == 0)
		return (true);
	else if (ft_strcmp(str, "_") == 0)
		return (true);
	if (ft_strncmp(str, "_+=", 3) == 0)
		return (true);
	else
		return (false);
}
