#include "../../include/minishell.h"

char	*strjoin_path(char *sepflag, char *separgv)
{
	char	*path;
	char	*tmp;

	path = ft_strjoin(sepflag, "/");
	if (path == NULL)
		return (NULL);
	tmp = path;
	path = ft_strjoin(path, separgv);
	free_str(tmp);
	return (path);
}

