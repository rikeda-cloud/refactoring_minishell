#include "include/expansion.h"
#include "include/minishell.h"

t_global_data data;

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

bool	exec_cmd(char *line)
{
	t_words	*word_list;
	t_tree_node	*root;
	bool		faild_flag;

	word_list = lexer(line);
	if (word_list == NULL)
		return (false);
	root = parser(word_list);
	if (root == NULL)
		return (false);
	faild_flag = false;
	expansion_tree(root, &faild_flag);
	if (faild_flag)
		return (false);
	/* if (do_command(root)) */
	/* 	return (false); */
	/* free_all(); */
	return (true);
}

void	exec_shell_loop(void)
{
	char	*line;

	while (1)
	{
		line = readline(PROMPT);
		if (line == NULL)
			break ;
		else if (line[0] != '\0')
		{
			exec_cmd(line);
			add_history(line);
		}
		free(line);
	}
}

int	main (void)
{
	signal(SIGINT, minishell_handler);
	signal(SIGQUIT, SIG_IGN);
	data.env_map = change_env_to_hash_map();
	if (data.env_map == NULL)
	{
		printf(FMT_ERR_CAN_NOT_CREATE_MAP);
		return (1);
	}
	data.crr_dir = getcwd(NULL, 0);
	data.error_number = 0;
	exec_shell_loop();
	/* free_all(); */
	return (data.error_number);
}
