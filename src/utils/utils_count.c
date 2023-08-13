/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:01:40 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/13 14:18:10 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static size_t	check_append_or_heredoc_pattern(const char *const str)
{
	if (str[0] == '>' && str[1] == '>')
		return (2);
	else if (str[0] == '<' && str[1] == '<')
		return (2);
	else
		return (1);
}

size_t	count_word_size(const char *str)
{
	size_t	size;
	bool	quote_flag;
	int		quote_char;

	size = 0;
	quote_flag = false;
	while (str[size] != '\0')
	{
		if (is_quotation(str[size]) && quote_flag && str[size] == quote_char)
			reverse_flag(&quote_flag);
		else if (is_quotation(str[size]) && quote_flag == false)
		{
			quote_char = str[size];
			reverse_flag(&quote_flag);
		}
		else if (!quote_flag && is_special_char(str[size]) && size != 0)
			return (size);
		else if (!quote_flag && is_special_char(str[size]) && size == 0)
			return (check_append_or_heredoc_pattern(&str[size]));
		size++;
	}
	return (size);
}

size_t	count_to_front_of_c(char *str, int c)
{
	size_t	size;

	size = 0;
	while (str[size] != '\0' && str[size] != c)
		size++;
	return (size);
}

size_t	count_env_size(const char *str)
{
	size_t	size;

	if (str == NULL)
		return (0);
	size = 0;
	str++;
	if (*str == '\0')
		return (0);
	if (*str == '?')
		return (1);
	while (str[size] != '\0')
	{
		if (ft_isalnum(str[size]) || str[size] == '_')
			size++;
		else
			break ;
	}
	return (size);
}

size_t	count_number_of_cmd(t_tree_node *node)
{
	size_t	size;

	node = get_leftmost_node(node);
	if (node->prev == NULL)
		return (1);
	else if (node->prev->prev == NULL)
		return (2);
	else
	{
		node = node->prev->prev->right;
		size = 3;
		while (node->prev->prev && node->prev->prev->right)
		{
			size++;
			node = node->prev->prev->right;
		}
	}
	return (size);
}
