#include "../../include/minishell.h"

char	**do_split(char *str, char c)
{
	char	**tmp;

	tmp = ft_split(str, c);
	if (tmp == NULL)
	{
		perror("spliterror");
		exit(1);
	}
	return (tmp);
}

char	*do_strjoin(char *s1, char *s2)
{
	char	*path;

	path = ft_strjoin(s1, s2);
	if (path == NULL)
	{
		perror("strjoinerror");
		exit(1);
	}
	return (path);
}
