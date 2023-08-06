/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:58:36 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/06 16:31:29 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	do_dup2(int old_fd, int new_fd, bool exit_flag, bool *err_flag)
{
	int	check_dup2;

	check_dup2 = dup2(old_fd, new_fd);
	if (check_dup2 < 0 && exit_flag == true)
		perror_exit("dup2", 1);
	else if (check_dup2 < 0 && exit_flag == false)
	{
		*err_flag = true;
		perror("dup2");
	}
}

void	do_close(int close_fd, bool exit_flag, bool *err_flag)
{
	int	check;

	check = close(close_fd);
	if (check < 0 && exit_flag == true)
		perror_exit("close", 1);
	else if (check < 0 && exit_flag == false)
	{
		*err_flag = true;
		perror("close");
	}
}

void	do_pipe(int *pipefd)
{
	int	check_pipe;

	check_pipe = pipe(pipefd);
	if (check_pipe < 0)
		perror_exit("pipe", 1);
}

pid_t	do_fork(void)
{
	pid_t	check;

	check = fork();
	if (check < 0)
		perror_exit("fork", 1);
	return (check);
}

void	do_execve(char *path, char **separgv, char **my_environ)
{
	int	check;

	check = execve(path, separgv, my_environ);
	if (check < 0)
	{
		ft_putstr_fd(separgv[0], 2);
		ft_putendl_fd(": command not found", 2);
		exit(127);
	}
}
