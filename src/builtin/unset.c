/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:57:41 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/13 14:15:55 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	my_unset(t_words *word_list, int fd, t_data *data, bool exit_flag)
{
	dup2_and_close_stdout(fd, exit_flag, &data->err_flag);
	if (data->err_flag)
	{
		data->err_code = 1;
		return ;
	}
	while (word_list != NULL)
	{
		delete_env(data->env_map, word_list->word);
		word_list = word_list->next;
	}
	data->err_code = 0;
}
