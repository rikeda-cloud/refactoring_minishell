#include "../../include/minishell.h"

void	do_close(int fd)
{
	int	check;

	check = 0;
	check = close(fd);
	if (check == -1)
	{
		perror("close");
		exit (1);
	}
}

int	do_pipe(int	*pipefd)
{
	int	check;

	check = pipe(pipefd);
	if (check == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		exit(1);
	}
	return (check);
}

pid_t	do_fork(void)
{
	pid_t	check;

	check = fork();
	if (check < 0)
	{
		ft_putstr_fd(strerror(errno), 2);
		exit(1);
	}
	return (check);
}

int	do_dup2(int pipefd, int fd)
{
	int	check;

	check = dup2(pipefd, fd);
	if (check == -1)
	{
		perror("dup2");
		exit (1);
	}
	else
		return (check);
}

char	*do_file_access(char *file)
{
	if (access(file, X_OK) == 0)
		return (file);
	else
	{
		perror("file");
		exit(127);
	}
}
