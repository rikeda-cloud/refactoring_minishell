#include "include/expansion.h"
#include "include/minishell.h"
#include "include/utils.h"

void	minishell_handler(int signal)
{
	if (signal == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	exec_command_line(const char *line, t_data *data)
{
	t_words		*word_list;
	t_tree_node	*root;

	data->err_flag = false;
	word_list = lexer(line, data);
	if (word_list == NULL)
		return ;
	root = parser(word_list, data);
	if (root == NULL)
		return ;
	expansion_tree(root, data);
	if (data->err_flag)
		return ;
	del_null_word_node_in_tree(root);
	data->root = root;
	/* do_command(root, data) */
	data->root = free_all_tree_node(root);
}

void	exec_shell_loop(t_data *data)
{
	while (true)
	{
		data->line = readline(PROMPT);
		if (data->line == NULL)
			break ;
		else if (data->line[0] != '\0')
		{
			add_history(data->line);
			exec_command_line(data->line, data);
		}
		free_str(data->line);
		data->err_flag = false;
	}
}

int	main (void)
{
	t_data	data;

	signal(SIGINT, minishell_handler);
	signal(SIGQUIT, SIG_IGN);
	data.env_map = change_environ_to_hash_map();
	data.crr_dir = getcwd(NULL, 0);
	data.err_code = 0;
	data.err_flag = false;
	data.root = NULL;
	data.line = NULL;
	exec_shell_loop(&data);
	free_all_data(&data);
	ft_putendl_fd("exit", STDOUT_FILENO);
	return (data.err_code);
}
