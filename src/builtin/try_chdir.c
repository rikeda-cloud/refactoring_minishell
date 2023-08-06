#include "../../include/minishell.h"

t_cd	try_chdir(const char *path, t_cd *crr_mode)
{
	struct stat	state;
	t_cd		tmp_mode;

	if (stat(path, &state) != 0)
		return (*crr_mode);
	else if (!S_ISDIR(state.st_mode))
		return (*crr_mode);
	else if (access(path, X_OK) == 0)
	{
		tmp_mode = chdir(path);
		if (tmp_mode == CD_SUCCESS)
			return (CD_SUCCESS);
		else
			return (*crr_mode);
	}
	else
	{
		if (*crr_mode == CD_NO_FILE || *crr_mode == CD_NO_PERMISSION)
			return (CD_NO_PERMISSION);
		else
			return (*crr_mode);
	}
}

t_cd	try_chdir_cdpath(char **cdpath, char *str)
{
	size_t	idx;
	t_cd	cd_mode;
	char	*joined_path;

	cd_mode = CD_NO_FILE;
	idx = 0;
	while (cdpath[idx] != NULL)
	{
		joined_path = strjoin_path(cdpath[idx++], str);
		if (joined_path == NULL)
			return (CD_MALLOC_ERR);
		cd_mode = try_chdir(joined_path, &cd_mode);
		if (cd_mode == CD_SUCCESS)
		{
			ft_putendl_fd(joined_path, STDOUT_FILENO);
			free_str(joined_path);
			return (CD_SUCCESS);
		}
		free_str(joined_path);
	}
	return (cd_mode);
}

t_cd	try_chdir_with_cdpath(t_env **map, char *str)
{
	t_env	*env_cdpath;
	char	**cdpath;
	t_cd	cd_mode;

	cd_mode = CD_NO_FILE;
	env_cdpath = select_env(map, "CDPATH");
	if (env_cdpath == NULL)
		return (try_chdir(str, &cd_mode));
	cdpath = ft_split(env_cdpath->value, ':');
	if (cdpath == NULL)
		return (CD_MALLOC_ERR);
	cd_mode = try_chdir_cdpath(cdpath, str);
	free_char_array(cdpath);
	if (cd_mode == CD_SUCCESS)
		return (CD_SUCCESS);
	cd_mode = try_chdir(str, &cd_mode);
	return (cd_mode);
}
