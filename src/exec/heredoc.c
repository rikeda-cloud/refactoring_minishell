#include "../../include/minishell.h"

static int	heredoc(const char *delimiter, t_token_type type, t_data *data)
{
	int		pipefd[2];
	char	*line;

	g_sig_mode = HEREDOC_MODE;
	pipe(pipefd);
	while (true)
	{
		ft_putchar_fd('>', STDOUT_FILENO);
		line = get_next_line(STDOUT_FILENO);
		/* line = readline(HEREDOC_PROMPT); */
		if (line == NULL)
			break ;
		else if (is_same_to_newline(line, delimiter))
		{
			free(line);
			break ;
		}
		if (type != DELIMITER_QUOTE)
			line = replace_all_env(line, data);
		if (line == NULL)
			break;
		ft_putstr_fd(line, pipefd[1]);
		free(line);
	}
	close(pipefd[1]);
    return (pipefd[0]);
}

static int    heredoc_check(t_words *head, t_data *data)
{
	int	get_fd;

	get_fd = 0;
    while(head != NULL && g_sig_mode != ENTER_CTRL_C_MODE)
    {
        if (head->token_type == HEREDOC)
        {
			if(get_fd != 0)
				close(get_fd);
            get_fd = heredoc(head->next->word, head->next->token_type, data);
            head = head->next->next;
        }
        else
			head = head->next;
    }
	return(get_fd);
}

int	*heredoc_loop(t_tree_node *root, t_data *data)
{
	t_tree_node *first_command;
    int			*table_fd;
	int			*tmp;

	first_command = root;
	table_fd = ft_calloc(4, 1000);
	tmp = table_fd;
	while(true)
    {
        *tmp++ = heredoc_check(root->word_list, data);
		if (is_last_cmd(root))
            break ;
		else if (root == first_command)
			root = root->prev->right;
		else
			root = root->prev->prev->right;
    }
	return (table_fd);
}
