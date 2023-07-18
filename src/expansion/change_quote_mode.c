#include "../../include/minishell.h"

void	change_quote_mode(int *mode, t_token_type type)
{
	if (*mode == SINGLE_Q_MODE || *mode == DOUBLE_Q_MODE)
		*mode = NOT_Q_MODE;
	else if (type == TMP_SINGLE_QUOTE)
		*mode = SINGLE_Q_MODE;
	else
		*mode = DOUBLE_Q_MODE;
}
