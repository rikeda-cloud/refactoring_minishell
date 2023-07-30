#include "../../include/minishell.h"

void	ft_putchar_fd(char c, int fd)
{
	if (write(fd, &c, 1) == -1)
		perror("Error");
}
