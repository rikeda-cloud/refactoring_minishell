#include "../../include/minishell.h"

static int change_wstatus_to_err_code(int wstatus)
{
	if (WIFEXITED(wstatus))
		return (WEXITSTATUS(wstatus));
	else
		return (128 + WTERMSIG(wstatus));
}

void    child_wait(t_tree_node *first_cmd, t_table *table, t_data *data)
{
	int	wstatus;
	t_tree_node	*cmd;
	size_t	idx;

	cmd = first_cmd;
	idx = 0;
    while(true)
    {
		if (is_last_cmd(cmd))
        {
			waitpid(table[idx++].pid, &wstatus, 0);
			data->err_code = change_wstatus_to_err_code(wstatus);
			break ;
        }
		else
			waitpid(table[idx++].pid, NULL, 0); 
		if (cmd == first_cmd)
            cmd = cmd->prev->right;
		else
            cmd = cmd->prev->prev->right;
    }
}
