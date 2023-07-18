#include "../../include/minishell.h"

void	no_pipe(char **argv)
{
	pid_t	pid;
	int		check;
	int		infd;

	pid = do_fork();
	if (pid == 0)
	{
		infd = open (argv[1], O_RDONLY);
		if (infd == -1)
		{
			ft_putendl_fd(strerror(errno), 2);
			exit (1);
		}
		do_dup2(infd, 0);
		do_close(infd);
		nopipe_file(argv);
	}
	check = wait (NULL);
	if (check == -1)
	{
		ft_putendl_fd(strerror(errno), 2);
		exit (1);
	}
}

void	nopipe_file(char **argv)
{
	int		outfd;
	char	**separgv;
	char	*path;

	separgv = do_split(argv[2], ' ');
	if (separgv[0] == NULL)
	{
		perror ("command not found");
		exit (127);
	}
	path = get_path(separgv[0]);
	outfd = open (argv[3], (O_CREAT | O_RDWR | O_TRUNC), 0644);
	if (outfd == -1)
	{
		ft_putendl_fd(strerror(errno), 2);
		exit (1);
	}
	do_dup2(outfd, 1);
	do_close(outfd);
	do_nopipe_cmd(path, separgv);
}

void	do_nopipe_cmd(char *path, char **separgv)
{
	int	check;

	check = execve(path, separgv, environ);
	if (check == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		exit (127);
	}
}

void	only_heredoc(char **argv)
{
	char	*str;
	int		outfd;

	outfd = open (argv[3], (O_CREAT | O_RDWR | O_APPEND), 0644);
	if (outfd == -1)
	{
		ft_putendl_fd(strerror(errno), 2);
		exit (1);
	}
	while (1)
	{
		str = get_next_line(0);
		if (str == NULL)
			break ;
		else if (ft_strncmp(str, argv[2], ft_strlen(argv[2])) == 0)
		{
			free (str);
			break ;
		}
		ft_putstr_fd(str, outfd);
		free(str);
	}
}
