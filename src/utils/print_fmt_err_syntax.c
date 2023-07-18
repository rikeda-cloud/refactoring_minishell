#include "../../include/minishell.h"

bool	print_fmt_err_syntax(char *unexpected_token)
{
	printf(FMT_ERR_SYNTAX, unexpected_token);
	return (true);
}

