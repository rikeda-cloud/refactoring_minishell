#include "../../include/minishell.h"

static bool	is_same_to_newline(const char *have_newline_str, const char *str)
{
	size_t	idx;

	idx = 0;
	while (have_newline_str[idx] != '\0' && have_newline_str[idx] != '\n')
	{
		if (have_newline_str[idx] != str[idx])
			return (false);
		idx++;
	}
	idx = 0;
	while (str[idx] != '\0')
	{
		if (have_newline_str[idx] != str[idx])
			return (false);
		idx++;
	}
	return (true);
}

static void	heredoc_not_save_data(const char *delimiter)
{
	char	*line;

	while (true)
	{
		line = get_next_line(STDIN_FILENO);
		/* line = readline(HEREDOC_PROMPT); */
		if (line == NULL)
			break ;
		else if (is_same_to_newline(line, delimiter))
		{
			free(line);
			break ;
		}
		free(line);
	}
}

static bool	empty_heredoc(t_words *word_list, t_words *ctrl_operator)
{
	t_words	*prev_word;

	prev_word = word_list;
	if (word_list != NULL)
		word_list = word_list->next;
	while (word_list!= NULL)
	{
		if (is_redirect(prev_word->token_type))
		{
			if (is_redirect(word_list->token_type))
				return (true);
		}
		if (prev_word->token_type == HEREDOC)
			heredoc_not_save_data(word_list->word);
		prev_word = word_list;
		word_list = word_list->next;
	}
	if (is_redirect(prev_word->token_type) && ctrl_operator != NULL)
		return (true);
	else if (is_redirect(prev_word->token_type) && ctrl_operator == NULL)
		return (true);
	return (false);
}

bool	apparently_heredoc(t_tree_node *node)
{
	node = get_leftmost_node(node);
	if (node->prev == NULL)
		return empty_heredoc(node->word_list, NULL);
	if (empty_heredoc(node->word_list, node->prev->word_list))
		return (true);
	node = node->prev->right;
	while (node->prev->prev != NULL)
	{
		if (empty_heredoc(node->word_list, node->prev->word_list))
			return (true);
		node = node->prev->prev->right;
	}
	return (empty_heredoc(node->word_list, NULL));
}

int	heredoc(const char *delimiter, t_token_type type, t_data *data)
{
	int		pipefd[2];
	char	*line;

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

int    heredoc_check(t_words *head, t_data *data)
{
	int	get_fd;

	get_fd = 0;
    while(head != NULL)
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
        if (root->prev == NULL || (root->prev->prev == NULL && root != root->prev->left))
            break ;
        else if (root == first_command)
            root = root->prev->right;
        else
            root = root->prev->prev->right;
    }
	return (table_fd);
}
