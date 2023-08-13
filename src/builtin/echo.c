/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:57:18 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/13 14:15:43 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	put_words_fd(t_words *word_list, int fd)
{
	while (word_list != NULL)
	{
		ft_putstr_fd(word_list->word, fd);
		if (word_list->next != NULL)
			ft_putchar_fd(' ', fd);
		word_list = word_list->next;
	}
}

void	my_echo(t_words *word_list, int fd, t_data *data, bool exit_flag)
{
	bool	option_flag;

	dup2_and_close_stdout(fd, exit_flag, &data->err_flag);
	if (data->err_flag)
	{
		data->err_code = 1;
		return ;
	}
	if (word_list == NULL)
		ft_putchar_fd('\n', STDOUT_FILENO);
	else
	{
		option_flag = is_option_n(word_list->word);
		if (option_flag)
			word_list = get_not_option_node(word_list);
		put_words_fd(word_list, STDOUT_FILENO);
		if (option_flag == false)
			ft_putchar_fd('\n', STDOUT_FILENO);
	}
	data->err_code = 0;
}
