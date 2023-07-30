#include "../../include/minishell.h"

void	free_all_and_exit(int err_code, t_data *data)
{
	int exit_code;

	exit_code = err_code;
	free_all_data(data);
	exit(exit_code);
}

void	my_exit(t_words *word_list, int fd, t_data *data)
{
	bool	can_exit_flag;

	if (fd != STDOUT_FILENO)
	{
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	ft_putendl_fd("exit", STDOUT_FILENO);
	if (word_list != NULL && ft_strcmp(word_list->word, "--") == 0)
		word_list = word_list->next;
	if (word_list == NULL)
		free_all_and_exit(data->err_code, data);
	can_exit_flag = calc_exit_status(word_list->word, data);
	if (can_exit_flag || word_list->next == NULL)
		free_all_and_exit(data->err_code, data);
	else
		err_many_arg("exit", &data->err_code);
}
