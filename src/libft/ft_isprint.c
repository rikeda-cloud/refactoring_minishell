#include "../../include/minishell.h"

int	ft_isprint(int c)
{
	return (!(c < ' ' || '~' < c));
}
