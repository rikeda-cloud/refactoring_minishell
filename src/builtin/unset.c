#include "../../include/minishell.h"

void	my_unset(t_words *word_list, int fd, t_data *data)
{
	dup2_and_close_3(fd);
	while (word_list != NULL)
	{
		delete_env(data->env_map, word_list->word);
		word_list = word_list->next;
	}
	data->err_code = 0;
}
