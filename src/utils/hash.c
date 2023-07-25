#include "../../include/minishell.h"

int	hash(int c)
{
	if (ft_islower(c))
		return ((c - 'a') + 1);
	else if (ft_isupper(c))
		return ((c - 'A') + 1);
	else
		return (0);
}
