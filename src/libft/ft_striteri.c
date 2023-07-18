#include "../../include/minishell.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	idx;

	idx = 0;
	if (s != NULL)
	{
		while (*s != '\0')
			f(idx++, s++);
	}
}
