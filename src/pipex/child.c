#include "../../include/minishell.h"

void	do_last_cmd(char *cmd)
{
	char	*path;
	char	**separgv;
	int		check;

	separgv = do_split(cmd, ' ');
	if (separgv[0] == NULL)
	{
		perror ("command not found");
		exit (127);
	}
	path = get_path(separgv[0]);
	check = execve(path, separgv, environ);
	if (check == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		exit (127);
	}
}

void	do_first_mid_cmd(char	*cmd, int *pipefd)
{
	char	*path;
	char	**separgv;
	int		check;

	separgv = do_split(cmd, ' ');
	if (separgv[0] == NULL)
	{
		perror ("command not found");
		exit (127);
	}
	path = get_path(separgv[0]);
	do_close(pipefd[0]);
	do_dup2(pipefd[1], 1);
	do_close (pipefd[1]);
	check = execve(path, separgv, environ);
	if (check == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		exit (127);
	}
}


void	last_cmd(char *outfile, char *infile, char *argv, int prev_fd)
{
	int	outfd;

	if (ft_strncmp(infile, "here_doc", 8) == 0)
		outfd = open (outfile, (O_CREAT | O_RDWR | O_APPEND), 0644);
	else
		outfd = open (outfile, (O_CREAT | O_RDWR | O_TRUNC), 0644);
	if (outfd == -1)
	{
		// write(2, "test\n", 5);
		ft_putstr_fd(strerror(errno), 2);
		exit (1);
	}
	do_dup2(prev_fd, 0);
	do_close(prev_fd);
	do_dup2(outfd, 1);
	do_close(outfd);
	do_last_cmd(argv);
}

void	mid_cmd(char	*cmd, int *pipefd, int prev_fd)
{
	char	**separgv;

	do_dup2(prev_fd, 0);
	do_close(prev_fd);
	separgv = do_split(cmd, ' ');
	if (separgv[0] == NULL)
	{
		perror ("command not found");
		exit (127);
	}
	do_first_mid_cmd(cmd, pipefd);
}

void	first_cmd(char *infile, char *argv, int *pipefd)
{
	int	infd;

	infd = open(infile, O_RDONLY);
	if (infd == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		do_close(pipefd[0]);
		do_close(pipefd[1]);
		exit (1);
	}
	do_dup2(infd, 0);
	do_close(infd);
	do_first_mid_cmd(argv, pipefd);
}
