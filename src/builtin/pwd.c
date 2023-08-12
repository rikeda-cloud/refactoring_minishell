/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:57:36 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/12 12:50:44 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	my_pwd(t_words *word_list, int fd, t_data *data, bool exit_flag)
{
	(void)word_list;
	dup2_and_close_stdout(fd, exit_flag, &data->err_flag);
	if (data->err_flag)
	{
		data->err_code = 1;
		return ;
	}
	if (data->crr_dir != NULL)
	{
		ft_putendl_fd(data->crr_dir, STDOUT_FILENO);
		data->err_code = 0;
	}
	else
	{
		print_err1(ERR_CRR_DIR_NOT_EXIST);
		data->err_code = 1;
	}
}
