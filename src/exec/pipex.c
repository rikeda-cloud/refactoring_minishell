#include "../../include/minishell.h"

char *str_to_command(t_tree_node *root)
{
    char    *command;
    t_words *tmp;

    command = root->word_list->word;
    tmp = root->word_list->next;
    while (tmp != NULL)
    {
        command = ft_strjoin(command, " ");
        command = ft_strjoin(command, tmp->word);
        tmp = tmp->next;
    }
    return(command);
}

void    command_loop(t_tree_node *root, t_data *data)
{
    t_tree_node *first_command;
    int         prevfd;
    int         *table;

    prevfd = 0;
    root = get_leftmost_node(root);
    first_command = root;
    table = heredoc_loop(root, data);
    while(true)
    {
        if (root->prev == NULL || (root->prev->prev == NULL && root != root->prev->left))
		{
            do_last_command(root, prevfd, *table++);
            break ;
        }
        prevfd = do_command(root, prevfd, *table++);
        if (root == first_command)
            root = root->prev->right;
        else
            root = root->prev->prev->right;
    }
    child_wait(root, first_command);
}
