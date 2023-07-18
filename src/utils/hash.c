#include "../../include/minishell.h"

int	hash(int c)
{
	if ('a' <= c && c <= 'z')
		return (c - 'a' + 1);
	else if ('A' <= c && c <= 'Z')
		return (c - 'A' + 1);
	else
		return (0);
}
