/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_word_list_to_cmd.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:58:16 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/12 12:51:19 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static size_t	count_cmd_seqargv_size(t_words *word_list)
{
	size_t	size;

	size = 0;
	while (word_list != NULL)
	{
		size++;
		word_list = word_list->next;
	}
	return (size);
}

static void	join_word_to_cmd(char **cmd, t_words *word_list)
{
	size_t	idx;

	idx = 0;
	while (word_list != NULL)
	{
		cmd[idx++] = word_list->word;
		word_list = word_list->next;
	}
}

char	**change_word_list_to_cmd(t_words *word_list)
{
	char	**cmd;
	size_t	size;

	size = count_cmd_seqargv_size(word_list);
	cmd = (char **)ft_calloc(sizeof(char *), (size + 1));
	if (cmd == NULL)
		return (NULL);
	join_word_to_cmd(cmd, word_list);
	return (cmd);
}
