#include "../../include/minishell.h"

int	heredoc(char *limiter)
{
	int		pipefd[2];
	char	*str;
	int		prev_fd;

	do_pipe(pipefd);
	while (1)
	{
		str = get_next_line(0);
		if (str == NULL)
			break ;
		else if (ft_strncmp(str, limiter, ft_strlen(limiter)) == 0)
		{
			free(str);
			break ;
		}
		ft_putstr_fd(str, pipefd[1]);
		free(str);
	}
	prev_fd = pipefd[0];
	do_close(pipefd[1]);
	return (prev_fd);
}
