/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_append.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:58:45 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/06 16:26:14 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	do_open_append(char *filename, bool exit_flag, bool *err_flag)
{
	int	fd;

	fd = open(filename, (O_RDWR | O_APPEND | O_CREAT), 0644);
	if (fd < 0 && exit_flag == true)
		perror_exit(filename, 1);
	else if (fd < 0 && exit_flag == false)
	{
		*err_flag = true;
		perror(filename);
	}
	return (fd);
}

void	redirect_append(t_words *fname, bool exit_flag, bool *err_flag)
{
	int	fd;

	fd = do_open_append(fname->word, exit_flag, err_flag);
	if (*err_flag)
		return ;
	do_dup2(fd, 1, exit_flag, err_flag);
	if (*err_flag)
		return ;
	do_close(fd, exit_flag, err_flag);
}
