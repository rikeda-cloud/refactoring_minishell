#include "../../include/minishell.h"

void	reverse_flag(bool *flag)
{
	if (*flag == true)
		*flag = false;
	else if (*flag == false)
		*flag = true;
}
