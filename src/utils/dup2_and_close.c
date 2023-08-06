#include "../../include/minishell.h"

void	dup2_and_close_stdin(int fd, bool exit_flag, bool *err_flag)
{
	if (fd != STDIN_FILENO)
	{
		do_dup2(fd, STDIN_FILENO, exit_flag, err_flag);
		do_close(fd, exit_flag, err_flag);
	}
}

void	dup2_and_close_pipefd(int *pipefd, bool exit_flag, bool *err_flag)
{
	do_close(pipefd[0], exit_flag, err_flag);
	do_dup2(pipefd[1], STDOUT_FILENO, exit_flag, err_flag);
	do_close(pipefd[1], exit_flag, err_flag);
}

void	dup2_and_close_stdout(int fd, bool exit_flag, bool *err_flag)
{
	if (fd != STDOUT_FILENO)
	{
		do_dup2(fd, STDOUT_FILENO, exit_flag, err_flag);
		do_close(fd, exit_flag, err_flag);
	}
}


