#include "../../include/minishell.h"

void	ft_putstr_fd(const char *s, int fd)
{
	if (s != NULL)
	{
		if (write(fd, s, ft_strlen(s)) == -1)
			perror("Error");
	}
}
