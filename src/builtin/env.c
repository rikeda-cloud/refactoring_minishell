#include "../../include/minishell.h"

void	my_env(t_words *word_list, int fd, t_data *data)
{
	char	**my_environ;
	char	**separgv;
	char	*path;

	dup2_and_close_stdout_fileno(fd);
	while (word_list != NULL && is_in_equal(word_list->word))
	{
		insert_or_update_env(word_list->word, data);
		word_list = word_list->next;
	}
	my_environ = change_map_to_environ(data->env_map, &data->err_flag);
	if (my_environ == NULL)
		return ;
	if (word_list == NULL)
		print_all_env(fmt_env, STDOUT_FILENO, data);
	else
		exec_normal_cmd_child_proc(word_list, data);
	{
		separgv = change_word_list_to_cmd(word_list);
		path = get_path(separgv[0], data);
		execve(path, separgv, my_environ);
	}
}
