#include "../../include/minishell.h"

int	parents(int *pipefd, size_t i, int argc, int prev_fd)
{
	if (i == 3)
	{
		prev_fd = pipefd[0];
		do_close(pipefd[1]);
		return (prev_fd);
	}
	else if (i == (size_t)argc - 1)
	{
		do_close(prev_fd);
		return (0);
	}
	else
	{
		do_close(prev_fd);
		prev_fd = pipefd[0];
		do_close(pipefd[1]);
		return (prev_fd);
	}
}

void	wait_child(char **argv, size_t i)
{
	int	check;

	check = 0;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		i = i - 1;
	while (i > 2)
	{
		check = wait (NULL);
		if (check == -1)
		{
			ft_putstr_fd(strerror(errno), 2);
			exit (1);
		}
		i--;
	}
}
