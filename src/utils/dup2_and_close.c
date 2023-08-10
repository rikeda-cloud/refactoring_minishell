/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup2_and_close.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:01:16 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/06 17:11:35 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	dup2_and_close_stdin(int fd, bool exit_flag, bool *err_flag)
{
	if (fd != STDIN_FILENO)
	{
		do_dup2(fd, STDIN_FILENO, exit_flag, err_flag);
		do_close(fd, exit_flag, err_flag);
	}
}

void	dup2_and_close_pipefd(int *fd, bool exit_flag, bool *err_flag)
{
	do_close(fd[0], exit_flag, err_flag);
	do_dup2(fd[1], STDOUT_FILENO, exit_flag, err_flag);
	do_close(fd[1], exit_flag, err_flag);
}

void	dup2_and_close_stdout(int fd, bool exit_flag, bool *err_flag)
{
	if (fd != STDOUT_FILENO)
	{
		do_dup2(fd, STDOUT_FILENO, exit_flag, err_flag);
		do_close(fd, exit_flag, err_flag);
	}
}
