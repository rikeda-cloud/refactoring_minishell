/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_read.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:58:51 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/06 16:29:10 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	do_open_read(char *filename, bool exit_flag, bool *err_flag)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0 && exit_flag == true)
		perror_exit(filename, 1);
	else if (fd < 0 && exit_flag == false)
	{
		*err_flag = true;
		perror(filename);
	}
	return (fd);
}

void	redirect_read(t_words *fname, bool exit_flag, bool *err_flag)
{
	int	fd;

	fd = do_open_read(fname->word, exit_flag, err_flag);
	if (*err_flag)
		return ;
	do_dup2(fd, 0, exit_flag, err_flag);
	if (*err_flag)
		return ;
	do_close(fd, exit_flag, err_flag);
}
