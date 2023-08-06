/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:58:39 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/06 17:04:09 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*wrap_replace_all_env(char *line, t_token_type type, t_data *data)
{
	if (type == DELIMITER_QUOTE)
		return (line);
	line = replace_all_env(line, data);
	if (line == NULL)
		data->err_flag = true;
	return (line);
}

static int	heredoc(const char *delimiter, t_token_type type, t_data *data)
{
	int		pipefd[2];
	char	*line;

	do_pipe(pipefd);
	while (data->err_flag == false)
	{
		line = readline(HEREDOC_PROMPT);
		if (line == NULL)
			break ;
		if (is_same_to_newline(line, delimiter) || g_sig_mode == HEREDOC_C_MODE)
		{
			free_str(line);
			break ;
		}
		line = wrap_replace_all_env(line, type, data);
		if (line == NULL)
			break ;
		ft_putendl_fd(line, pipefd[1]);
		free_str(line);
	}
	do_close(pipefd[1], false, &data->err_flag);
	return (pipefd[0]);
}

static int	heredoc_check(t_words *head, t_data *data)
{
	int	get_fd;

	get_fd = 0;
	while (head != NULL && data->err_flag == false)
	{
		if (head->token_type == HEREDOC)
		{
			if (get_fd != 0)
				do_close(get_fd, false, &data->err_flag);
			if (data->err_flag)
				break ;
			g_sig_mode = HEREDOC_MODE;
			get_fd = heredoc(head->next->word, head->next->token_type, data);
			if (g_sig_mode == HEREDOC_C_MODE)
				data->err_flag = true;
			head = head->next->next;
		}
		else
			head = head->next;
	}
	return (get_fd);
}

t_table	*heredoc_loop(t_tree_node *root, t_data *data)
{
	t_table		*table;
	size_t		idx;
	t_tree_node	*first_command;

	first_command = root;
	table = ft_calloc(sizeof(t_table), count_number_of_cmd(root));
	if (table == NULL)
		data->err_flag = true;
	idx = 0;
	while (data->err_flag == false)
	{
		table[idx++].fd = heredoc_check(root->word_list, data);
		if (is_last_cmd(root))
			break ;
		else if (root == first_command)
			root = root->prev->right;
		else
			root = root->prev->prev->right;
	}
	if (data->err_flag)
		return (free_table(table));
	return (table);
}
