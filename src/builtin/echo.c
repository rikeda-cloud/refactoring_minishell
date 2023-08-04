#include "../../include/minishell.h"

void	put_words_fd(t_words *word_list, int fd)
{
	while (word_list != NULL)
	{
		ft_putstr_fd(word_list->word, fd);
		if (word_list->next != NULL)
			ft_putchar_fd(' ', fd);
		word_list = word_list->next;
	}
}

void	my_echo(t_words *word_list, int fd, t_data *data)
{
	bool	option_flag;

	dup2_and_close_3(fd);
	if (word_list == NULL)
		ft_putchar_fd('\n', STDOUT_FILENO);
	else
	{
		option_flag = is_option_n(word_list->word);
		if (option_flag)
			word_list = get_not_option_node(word_list);
		put_words_fd(word_list, STDOUT_FILENO);
		if (option_flag == false)
			ft_putchar_fd('\n', STDOUT_FILENO);
	}
	data->err_code = 0;
}
