#include "include/minishell.h"

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

bool	exec_command_line(t_data *data, char *line)
{
	t_words	*word_list;
	t_tree_node	*root;
	bool		faild_flag;

	word_list = lexer(line, data);
	if (word_list == NULL || data->err_number != 0)
		return (false);
	root = parser(word_list, data);
	if (root == NULL || data->err_number != 0)
		return (false);
	faild_flag = false;
	expansion_tree(root, &faild_flag, data);
	if (faild_flag)
		return (false);
	/* if (do_command(root)) */
	/* 	return (false); */
	/* free_all(); */
	return (true);
}

void	exec_shell_loop(t_data *data)
{
	char	*line;

	while (true)
	{
		line = readline(PROMPT);
		if (line == NULL)
		{
			write(1, "\nexit\n", 6);
			break ;
		}
		else if (line[0] != '\0')
		{
			add_history(line);
			exec_command_line(data, line);
		}
		free(line);
	}
}

int	main (void)
{
	t_data	data;
	signal(SIGINT, minishell_handler);
	signal(SIGQUIT, SIG_IGN);
	data.env_map = change_environ_to_hash_map();
	if (data.env_map == NULL)
	{
		printf(FMT_ERR_CAN_NOT_CREATE_MAP);
		return (1);
	}
	data.crr_dir = getcwd(NULL, 0);
	data.err_number = 0;
	exec_shell_loop(&data);
	free_hash_map(data.env_map);
	free_str(data.crr_dir);
	return (data.err_number);
}
