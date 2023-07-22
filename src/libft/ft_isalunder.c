#include "../../include/minishell.h"

int	ft_isalunder(int c)
{
	return (ft_isalpha(c) || c == '_');
}
