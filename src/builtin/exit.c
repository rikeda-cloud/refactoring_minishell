/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:57:24 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/06 14:57:25 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	my_exit(t_words *word_list, int fd, t_data *data, bool exit_flag)
{
	bool	can_exit_flag;

	dup2_and_close_stdout(fd, exit_flag, &data->err_flag);
	if (data->err_flag)
	{
		data->err_code = 1;
		return (true);
	}
	if (word_list != NULL && ft_strcmp(word_list->word, "--") == 0)
		word_list = word_list->next;
	if (word_list == NULL)
		return (true);
	can_exit_flag = calc_exit_status(word_list->word, data);
	if (can_exit_flag == false && word_list->next != NULL)
	{
		err_many_arg("exit", &data->err_code);
		return (false);
	}
	return (true);
}
