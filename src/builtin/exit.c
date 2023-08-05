#include "../../include/minishell.h"

bool	my_exit(t_words *word_list, int fd, t_data *data)
{
	bool	can_exit_flag;

	dup2_and_close_stdout_fileno(fd);
	if (word_list != NULL && ft_strcmp(word_list->word, "--") == 0)
		word_list = word_list->next;
	if (word_list == NULL)
		return (true);
	can_exit_flag = calc_exit_status(word_list->word, data);
	if (can_exit_flag == false && word_list->next != NULL)
	{
		err_many_arg("exit", &data->err_code);
		return (false);
	}
	return (true);
}
