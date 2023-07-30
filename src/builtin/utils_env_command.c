#include "../../include/minishell.h"

bool	return_true(char *str)
{
	(void)str;
	return (true);
}

bool	is_null(char *str)
{
	return (str == NULL);
}
