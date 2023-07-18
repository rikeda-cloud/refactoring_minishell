#include "../../include/minishell.h"
#include <unistd.h>

int	exit_have_arguments_pattern(t_words *word_list)
{
	int		exit_status;
	char	*word;

	if (word_list->next == NULL)
		exit_status = calc_exit_status(word_list->word);
	else
	{
		word = word_list->word;
		if (word[0] == '-' && word[1] == '-' && word[2] == '\0')
			exit_status = calc_exit_status(word_list->next->word);
		else
		{
			printf(FMT_ERR_MANY_ARG_EXIT, word_list->word);
			exit_status = 2;
		}
	}
	return (exit_status);
}

void	my_exit(t_words *word_list, int fd)
{
	int	exit_status;

	if (fd != STDOUT_FILENO)
	{
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	write(STDOUT_FILENO, "exit\n", 5);
	if (word_list == NULL)
		exit_status = calc_exit_status(NULL);
	else
		exit_status = exit_have_arguments_pattern(word_list);
	exit(exit_status);
}
