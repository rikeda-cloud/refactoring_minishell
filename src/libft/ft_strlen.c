#include "../../include/minishell.h"

size_t	ft_strlen(const char *str)
{
	size_t	counter;

	if (str == NULL)
		return (0);
	counter = 0;
	while (*str++ != '\0')
		counter++;
	return (counter);
}
