#include "../../include/minishell.h"

char	*do_file_access(char *file)
{
	if (access(file, X_OK) == 0)
		return (file);
	else
	{
		perror("file");
		exit(127);
	}
}
