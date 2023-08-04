#include "../../include/minishell.h"

void	exec_builtin_cmd_child_proc(t_words *word_list, t_data *data)
{
	do_builtin_cmd(word_list, data);
	/* free_all_data(data); */
	exit(data->err_code);
}

void	exec_normal_cmd_child_proc(t_words *word_list, t_data *data)
{
	char	**separgv;
	char	**my_environ;
	char	*path;

	separgv = change_word_list_to_cmd(word_list);
	if (separgv == NULL)
		return ;
	path = get_path(separgv[0], data);
	if (path == NULL)
		return ;
	my_environ = change_map_to_environ(data->env_map);
	if (my_environ == NULL)
		return ;
	if (execve(path, separgv, my_environ) == -1)
		exit(1111111111);
}
