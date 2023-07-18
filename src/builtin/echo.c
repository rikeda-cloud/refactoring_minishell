#include "../../include/minishell.h"
#include <unistd.h>

void	put_words_fd(t_words *word_list, int fd)
{
	while (word_list != NULL)
	{
		if (is_option(word_list->word, 'n') == false)
		{
			ft_putstr_fd(word_list->word, fd);
			if (word_list->next != NULL)
				ft_putchar_fd(' ', fd);
		}
		word_list = word_list->next;
	}
}

void	my_echo(t_words *word_list, int fd)
{
	bool	option_flag;

	if (fd != STDOUT_FILENO)
	{
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	option_flag = is_option_n(word_list);
	put_words_fd(word_list, STDOUT_FILENO);
	if (option_flag == false)
		ft_putchar_fd('\n', STDOUT_FILENO);
}
