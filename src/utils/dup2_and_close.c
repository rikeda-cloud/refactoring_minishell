#include "../../include/minishell.h"

void	dup2_and_close_1(int fd)
{
	if (fd != STDIN_FILENO)
	{
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
}

void	dup2_and_close_2(int *pipefd)
{
	close(pipefd[0]);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);
}

void	dup2_and_close_3(int fd)
{
	if (fd != STDOUT_FILENO)
	{
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
}


