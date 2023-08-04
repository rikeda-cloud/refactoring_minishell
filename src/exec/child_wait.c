#include "../../include/minishell.h"

static int change_wstatus_to_err_code(int wstatus)
{
	if (WIFEXITED(wstatus))
		return (WEXITSTATUS(wstatus));
	else
		return (128 + WTERMSIG(wstatus));
}

void    child_wait(t_tree_node *root, t_tree_node *first_cmd, t_data *data)
{
	int	wstatus;

    root = first_cmd;
    while(true)
    {
		if (root->prev == NULL || (root->prev->prev == NULL && root != root->prev->left))
        {
			waitpid(root->word_list->command_pid, &wstatus, 0);
			data->err_code = change_wstatus_to_err_code(wstatus);
			break ;
        }
		else
			waitpid(root->word_list->command_pid, NULL, 0); 
		if (root == first_cmd)
            root = root->prev->right;
		else
            root = root->prev->prev->right;
    }
}
