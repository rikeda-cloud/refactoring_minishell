#include "../../include/minishell.h"


void	check_argc(int argc)
{
	if (argc <= 3)
	{
		perror("./pipex file1 cmd1 cmd2 file2");
		exit (1);
	}
}

void	choice_case_cmd(int argc, char **argv)
{
	size_t	i;
	pid_t	pid;
	int		pipefd[2];
	int		prev_fd;

	i = 2;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0 && ft_strlen(argv[1]) == 8)
	{
		/* prev_fd = heredoc(argv[2]); */
		prev_fd = heredoc(argv[2], 1, NULL);
		i = i + 1;
	}
	while (i <= (size_t)argc - 2)
	{
		if (i != (size_t)argc -2 && argc != 4)
			do_pipe(pipefd);
		pid = do_fork();
		if (pid == 0 && i == 2 && argc != 4)
			first_cmd(argv[1], argv[i], pipefd);
		else if (pid == 0 && i == (size_t)argc -2)
			last_cmd(argv[argc - 1], argv[1], argv[i], prev_fd);
		else if (pid == 0)
			mid_cmd(argv[i], pipefd, prev_fd);
		prev_fd = parents(pipefd, ++i, argc, prev_fd);
	}
	wait_child(argv, i);
}
