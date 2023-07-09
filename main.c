#include "include/minishell.h"

int		status;

/* void	minishell_handler(int signal, siginfo_t *info, void *ctx) */
void	minishell_handler(int signal)
{
	if (signal == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

char	*get_env_path(void)
{
	char	*path;

	path = getenv("PATH");
	return (path);
}

char	*search_absolute_command_path(char *command, char **path_ary)
{
	char	*path;
	size_t	idx;

	idx = 0;
	while (path_ary[idx] != NULL)
	{
		path = ft_strjoin(path_ary[idx], command);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		idx++;
	}
	return (NULL);
}

char	*search_exec_path(char *command)
{
	char	**path_ary;
	char	*path;

	if (access(command, X_OK) == 0)
		return (command);
	path = get_env_path();
	if (path == NULL)
	{
		printf("Error: getenv");
		return (NULL);
	}
	command = ft_strjoin("/", command);
	if (command == NULL)
	{
		printf("Error: malloc\n");
		return (NULL);
	}
	path_ary = ft_split(path, ':');
	if (path_ary == NULL)
	{
		printf("Error: malloc\n");
		return (NULL);
	}
	return (search_absolute_command_path(command, path_ary));
}

void	exec_cmd(char *str)
{
	pid_t	pid;
	char	**seqargv;
	char	*command_path;

	seqargv = ft_split(str, ' ');
	if (seqargv == NULL)
	{
		printf("Error: malloc\n");
		return ;
	}
	command_path = search_exec_path(seqargv[0]);
	if (command_path == NULL)
	{
		printf("minishell: %s: command not found\n", seqargv[0]);
		return ;
	}
	else
	{
		pid = fork();
		if (pid < 0)
			printf("Error: pid < 0\n");
		else if (pid == 0)
			execve(command_path, seqargv, environ);
		else
		{
			wait(&status);
			status = WEXITSTATUS(status);
		}
	}
}

void	exec_shell(void)
{
	char	*line;

	while (1)
	{
		line = readline(PROMPT);
		if (line == NULL)
		{
			printf("Ctl + D pushed!!\n");
			/* free_all(); */
			break ;
		}
		else if (line[0] != '\0')
		{
			add_history(line);
			exec_cmd(line);
		}
		free(line);
	}
}

int	main (void)
{
	signal(SIGINT, minishell_handler);
	signal(SIGQUIT, SIG_IGN);

	/* struct sigaction	sa; */
	/* signal(SIGQUIT, SIG_IGN); */
	/* memset(&sa, 0, sizeof(struct sigaction)); */
	/* sigemptyset(&sa.sa_mask); */
	/* sigaddset(&sa.sa_mask, SIGINT); */
	/* sa.sa_sigaction = minishell_handler; */
	/* sa.sa_flags = SA_SIGINFO; */
	/* if (sigaction(SIGINT, &sa, NULL) < 0) */
	/* 	return (1); */
	status = 0;
	exec_shell();
	return (status);
}
