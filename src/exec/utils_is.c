/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_is.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:59:01 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/06 16:29:22 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	is_builtin_cmd(const char *cmd)
{
	if (cmd == NULL)
		return (false);
	if (ft_strcmp(cmd, "cd") == 0)
		return (true);
	else if (ft_strcmp(cmd, "echo") == 0)
		return (true);
	else if (ft_strcmp(cmd, "env") == 0)
		return (true);
	else if (ft_strcmp(cmd, "exit") == 0)
		return (true);
	else if (ft_strcmp(cmd, "export") == 0)
		return (true);
	else if (ft_strcmp(cmd, "pwd") == 0)
		return (true);
	else if (ft_strcmp(cmd, "unset") == 0)
		return (true);
	else
		return (false);
}

bool	is_builtin_cmd_alone_without_env(t_tree_node *node)
{
	t_words	*word_list;

	node = get_leftmost_node(node);
	word_list = node->word_list;
	while (word_list != NULL)
	{
		if (is_redirect(word_list->token_type))
			word_list = word_list->next->next;
		else if (is_builtin_cmd(word_list->word) && node->prev == NULL)
		{
			if (ft_strcmp(word_list->word, "env") != 0)
				return (true);
			else
				return (false);
		}
		else
			return (false);
	}
	return (false);
}

bool	is_last_cmd(t_tree_node *root)
{
	if (root->prev == NULL)
		return (true);
	else if (root->prev->prev == NULL && root != root->prev->left)
		return (true);
	else
		return (false);
}

bool	is_same_to_newline(const char *have_newline_str, const char *str)
{
	size_t	idx;

	idx = 0;
	while (have_newline_str[idx] != '\0' && have_newline_str[idx] != '\n')
	{
		if (have_newline_str[idx] != str[idx])
			return (false);
		idx++;
	}
	idx = 0;
	while (str[idx] != '\0')
	{
		if (have_newline_str[idx] != str[idx])
			return (false);
		idx++;
	}
	return (true);
}
