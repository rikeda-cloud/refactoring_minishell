/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_write.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:58:54 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/12 12:51:33 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	do_open_write(char *filename, bool exit_flag, bool *err_flag)
{
	int	fd;

	fd = open(filename, (O_RDWR | O_CREAT | O_TRUNC), 0644);
	if (fd < 0 && exit_flag == true)
		perror_exit(filename, 1);
	else if (fd < 0 && exit_flag == false)
	{
		*err_flag = true;
		perror(filename);
	}
	return (fd);
}

void	redirect_write(t_words *fname, bool exit_flag, bool *err_flag)
{
	int	fd;

	fd = do_open_write(fname->word, exit_flag, err_flag);
	if (*err_flag)
		return ;
	do_dup2(fd, 1, exit_flag, err_flag);
	if (*err_flag)
		return ;
	do_close(fd, exit_flag, err_flag);
}
