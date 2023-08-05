#include "include/minishell.h"

volatile sig_atomic_t	g_sig_mode;

/* /1* ------------------------------------------------------------------------ *1/ */
/* char	*type_to_char(int token_type) */
/* { */
/* 	if (token_type == WORD) */
/* 		return ("WORD"); */
/* 	else if (token_type == PIPE) */
/* 		return ("PIPE"); */
/* 	else if (token_type == WRITE) */
/* 		return ("WRITE"); */
/* 	else if (token_type == READ) */
/* 		return ("READ"); */
/* 	else if (token_type == APPEND) */
/* 		return ("APPEND"); */
/* 	else if (token_type == HEREDOC) */
/* 		return ("HEREDOC"); */
/* 	else if (token_type == COMMAND) */
/* 		return ("COMMAND"); */
/* 	else if (token_type == DELIMITER) */
/* 		return ("DELIMITER"); */
/* 	else if (token_type == DELIMITER_QUOTE) */
/* 		return ("DELIMITER_QUOTE"); */
/* 	else */
/* 		return ("Error"); */
/* } */

/* size_t	print_words(t_words *words) */
/* { */
/* 	size_t	size; */
	
/* 	size = 0; */
/* 	while (words != NULL) */
/* 	{ */
/* 		printf("[[%s]:%s]", type_to_char(words->token_type), words->word); */
/* 		if (words->next != NULL) */
/* 			printf(" -> "); */
/* 		words = words->next; */
/* 		size++; */
/* 	} */
/* 	printf("\n"); */
/* 	return (size); */
/* } */

/* void	print_tree(t_tree_node *node) */
/* { */
/* 	if (node != NULL && node->word_list != NULL) */
/* 	{ */
/* 		print_tree(node->left); */
/* 		printf("%12s : ", type_to_char(node->node_type)); */
/* 		print_words(node->word_list); */
/* 		print_tree(node->right); */
/* 	} */
/* } */
/* /1* ------------------------------------------------------------------------ *1/ */

void	exec_command_line(const char *line, t_data *data)
{
	t_tree_node	*root;

	g_sig_mode = NORMAL_MODE;
	data->err_flag = false;
	root = parser(line, data);
	if (root == NULL)
	{
		if (data->err_flag)
			data->err_code = 1;
		return ;
	}
	expansion_tree(root, data);
	if (data->err_flag)
	{
		free_all_tree_node(root);
		data->err_code = 1;
		return ;
	}
	delete_null_word_node_in_tree(root);
	cmd_loop(root, data);
	free_all_tree_node(root);
}

void	exec_shell_loop(t_data *data)
{
	char	*line;

	while (true)
	{
		g_sig_mode = READLINE_MODE;
		line = readline(PROMPT);
		if (line == NULL)
			break ;
		else if (line[0] != '\0')
		{
			if (g_sig_mode == READLINE_C_MODE)
				data->err_code = 130;
			add_history(line);
			exec_command_line(line, data);
		}
		line = free_str(line);
	}
}

int	main (int argc, char **argv, const char **envp)
{
	t_data	data;

	(void)argc;
	(void)argv;
	g_sig_mode = NORMAL_MODE;
	signal(SIGINT, minishell_handler);
	signal(SIGQUIT, SIG_IGN);
	rl_event_hook = heredoc_handler;
	data.env_map = change_environ_to_map(envp);
	data.crr_dir = getcwd(NULL, 0);
	data.err_code = 0;
	data.err_flag = false;
	exec_shell_loop(&data);
	free_all_data(&data);
	ft_putendl_fd("exit", STDERR_FILENO);
	return (data.err_code);
}
