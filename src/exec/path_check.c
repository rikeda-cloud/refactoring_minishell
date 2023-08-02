#include "../../include/minishell.h"

static char	*check_access(char *flag, char *separgv)
{
	char	**sepflag;
	size_t	i;
	char	*path;
	int		check;
	char	*tmp;

	i = 0;
	sepflag = ft_split(flag, ':');
	while (sepflag[i] != NULL)
	{
		tmp = ft_strjoin(sepflag[i], "/");
		path = ft_strjoin(tmp, separgv);
		free(tmp);
		check = access(path, X_OK);
		if (check == 0)
		{
			return (path);
			break ;
		}
		free (path);
		i++;
	}
	ft_putstr_fd("command not found: ", 2);
	ft_putendl_fd(separgv, 2);
	exit (127);
}

char	*get_path(char *separgv)
{
	size_t	i;
	char	*flag;

	i = 0;
	flag = NULL;
	if (ft_strchr_asaka(separgv, '/') == 1)
		return (do_file_access(separgv));
	while (environ[i] != NULL)
	{
		if (ft_strncmp(environ[i], "PATH=", 5) == 0)
		{
			flag = environ[i];
			break ;
		}
		i++;
	}
	if (flag == NULL)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putendl_fd(separgv, 2);
		exit (127);
	}
	flag = flag + ft_strlen("PATH=");
	return (check_access(flag, separgv));
}
