#include "../../include/minishell.h"

void    cmd_loop(t_tree_node *root, t_data *data)
{
    int         prevfd;
    int         *table;

    prevfd = 0;
    root = get_leftmost_node(root);
    table = heredoc_loop(root, data);
	if (table == NULL)
	{
		data->err_code = 130;
		return ;
	}
	g_sig_mode = EXEC_MODE;
	if (is_builtin_cmd_alone_without_env(root))
		do_builtin_cmd_alone_without_env(root, data);
	else
		do_normal_cmd(root, prevfd, table, data);
	free_int_array(table);
}
