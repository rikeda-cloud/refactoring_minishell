#include "../../include/minishell.h"


void    command_loop(t_tree_node *root, t_data *data)
{
    t_tree_node *first_command;
    int         prevfd;
    int         *table;

    prevfd = 0;
    root = get_leftmost_node(root);
    first_command = root;
    table = heredoc_loop(root, data);
	g_sig_mode = EXEC_MODE;
	if (is_builtin_cmd_alone_without_env(root))
		do_builtin_cmd_alone_without_env(root->word_list, data);
	else
	{
		while(true)
		{
			if (is_last_cmd(root))
			{
				do_lst_cmd(root, prevfd, *table++, data);
				break ;
			}
			prevfd = do_cmd(root, prevfd, *table++, data);
			if (root == first_command)
				root = root->prev->right;
			else
				root = root->prev->prev->right;
		}
		child_wait(root, first_command, data);
	}
}
