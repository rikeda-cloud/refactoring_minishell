#include "../../include/minishell.h"

void	my_pwd(t_words *word_list, int fd)
{
	char	*path_name;
	if (fd != STDOUT_FILENO)
	{
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	path_name = getcwd(NULL, 0);
	if (path_name == NULL)
		printf("getcwd ERR\n");
	else
	{
		printf("%s\n", path_name);
		free(data.crr_dir);
		data.crr_dir = path_name;
	}
}
