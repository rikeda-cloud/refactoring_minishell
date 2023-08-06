#include "../../include/minishell.h"

static char	*do_file_access(char *file)
{
	if (access(file, X_OK) == 0)
		return (file);
	else
	{
		perror("file");
		exit(127);
	}
}

static char	*check_access(char *flag, char *separgv, t_data *data)
{
	char	**sepflag;
	size_t	i;
	char	*path;

	i = 0;
	sepflag = ft_split(flag, ':');
	while (sepflag[i] != NULL)
	{
		path = strjoin_path(sepflag[i++], separgv);
		if (path == NULL)
			break;
		if (access(path, X_OK) == 0)
		{
			free_char_array(sepflag);
			return (path);
		}
		free_str(path);
	}
	err_no_file(separgv, &data->err_code);
	free_char_array(sepflag);
	exit (127);
}

char	*get_path(char *separgv, t_data *data)
{
	t_env	*env_path;

	if (is_c_in_str(separgv, '/'))
		return (do_file_access(separgv));
	env_path = select_env(data->env_map, "PATH");
	if (env_path == NULL || env_path->value == NULL)
	{
		err_no_file(separgv, &data->err_code);
		exit (127);
	}
	return (check_access(env_path->value, separgv, data));
}