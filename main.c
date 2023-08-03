#include "include/minishell.h"

volatile sig_atomic_t	g_sig_mode;

/* ------------------------------------------------------------------------ */
char	*type_to_char(int token_type)
{
	if (token_type == WORD)
		return ("WORD");
	else if (token_type == PIPE)
		return ("PIPE");
	else if (token_type == WRITE)
		return ("WRITE");
	else if (token_type == READ)
		return ("READ");
	else if (token_type == APPEND)
		return ("APPEND");
	else if (token_type == HEREDOC)
		return ("HEREDOC");
	else if (token_type == COMMAND)
		return ("COMMAND");
	else if (token_type == DELIMITER)
		return ("DELIMITER");
	else if (token_type == DELIMITER_QUOTE)
		return ("DELIMITER_QUOTE");
	else
		return ("Error");
}

size_t	print_words(t_words *words)
{
	size_t	size;
	
	size = 0;
	while (words != NULL)
	{
		printf("[[%s]:%s]", type_to_char(words->token_type), words->word);
		if (words->next != NULL)
			printf(" -> ");
		words = words->next;
		size++;
	}
	printf("\n");
	return (size);
}

void	print_tree(t_tree_node *node)
{
	if (node != NULL && node->word_list != NULL)
	{
		print_tree(node->left);
		printf("%12s : ", type_to_char(node->node_type));
		print_words(node->word_list);
		print_tree(node->right);
	}
}

void	builtin_exec(t_tree_node *root, t_data *data)
{
	root = get_leftmost_node(root);
	if (root->prev == NULL)
	{
		if (ft_strcmp(root->word_list->word, "cd") == 0)
			my_cd(root->word_list->next, STDOUT_FILENO, data);
		else if (ft_strcmp(root->word_list->word, "echo") == 0)
			my_echo(root->word_list->next, STDOUT_FILENO, data);
		else if (ft_strcmp(root->word_list->word, "exit") == 0)
			my_exit(root->word_list->next, STDOUT_FILENO, data);
		else if (ft_strcmp(root->word_list->word, "export") == 0)
			my_export(root->word_list->next, STDOUT_FILENO, data);
		else if (ft_strcmp(root->word_list->word, "pwd") == 0)
			my_pwd(root->word_list->next, STDOUT_FILENO, data);
		else if (ft_strcmp(root->word_list->word, "unset") == 0)
			my_unset(root->word_list->next, STDOUT_FILENO, data);
		else if (ft_strcmp(root->word_list->word, "env") == 0)
			my_env(root->word_list->next, STDOUT_FILENO, data);
	}
}

/* ------------------------------------------------------------------------ */

void	exec_command_line(const char *line, t_data *data)
{
	t_tree_node	*root;

	g_sig_mode = NORMAL;
	data->err_flag = false;
	root = parser(line, data);
	if (root == NULL)
		return ;
	expansion_tree(root, data);
	if (data->err_flag)
	{
		data->root = free_all_tree_node(root);
		return ;
	}
	delete_null_word_node_in_tree(root);
	data->root = root;
	/* print_tree(root); */
	/* builtin_exec(root, data); */
	command_loop(root, data);
	data->root = free_all_tree_node(root);
}

void	exec_shell_loop(t_data *data)
{
	while (true)
	{
		g_sig_mode = READLINE_MODE;
		/* data->line = readline(PROMPT); */
		data->line = get_next_line(STDIN_FILENO);
		if (data->line == NULL)
			break ;
		else if (data->line[0] != '\0')
		{
			if (g_sig_mode == ENTER_CTRL_C_MODE)
				data->err_code = 130;
			/* add_history(data->line); */
			exec_command_line(data->line, data);
		}
		data->line = free_str(data->line);
	}
}

int	main (int argc, char **argv, const char **envp)
{
	t_data	data;

	(void)argc;
	(void)argv;
	signal(SIGINT, minishell_handler);
	signal(SIGQUIT, SIG_IGN);
	data.env_map = change_environ_to_map(envp);
	data.crr_dir = getcwd(NULL, 0);
	data.err_code = 0;
	data.err_flag = false;
	data.root = NULL;
	data.line = NULL;
	g_sig_mode = NORMAL;
	exec_shell_loop(&data);
	free_all_data(&data);
	ft_putendl_fd("exit", STDERR_FILENO);
	return (data.err_code);
}
