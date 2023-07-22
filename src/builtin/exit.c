#include "../../include/minishell.h"

int	exit_have_arguments_pattern(t_words *word_list, t_data *data)
{
	int		can_exit_flag;
	char	*word;

	if (word_list->next == NULL)
		can_exit_flag = calc_exit_status(word_list->word, data);
	else
	{
		word = word_list->word;
		if (word[0] == '-' && word[1] == '-' && word[2] == '\0')
			can_exit_flag = calc_exit_status(word_list->next->word, data);
		else
		{
			printf(FMT_ERR_MANY_ARG_EXIT);
			data->err_number = 2;
			can_exit_flag = false;
		}
	}
	return (can_exit_flag);
}

void	my_exit(t_words *word_list, int fd, t_data *data)
{
	bool	can_exit_flag;

	if (fd != STDOUT_FILENO)
	{
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	write(STDOUT_FILENO, "exit\n", 5);
	if (word_list != NULL && ft_strcmp(word_list->word, "--") == 0)
		word_list = word_list->next;
	if (word_list == NULL)
		exit(0);
	can_exit_flag = calc_exit_status(word_list->word, data);
	if (can_exit_flag || word_list->next == NULL)
		exit(data->err_number);
	else
		data->err_number = 1;
}
