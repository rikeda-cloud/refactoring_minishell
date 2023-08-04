#include "../../include/minishell.h"

static void	change_pwd_oldpwd_crrdir(t_data *data, bool null_char_flag)
{
	if (null_char_flag)
	{
		update_env(data->env_map, "OLDPWD", data->crr_dir);
		update_env(data->env_map, "PWD", data->crr_dir);
	}
	else
	{
		update_env(data->env_map, "OLDPWD", data->crr_dir);
		data->crr_dir = free_str(data->crr_dir);
		data->crr_dir = getcwd(NULL, 0);
		update_env(data->env_map, "PWD", data->crr_dir);
	}
	data->err_code = 0;
}

int	chdir_with_cdpath(t_env **map, const char *str)
{
	t_env	*env_cdpath;
	char	**cdpath;
	size_t	idx;

	env_cdpath = select_env(map, "CDPATH");
	if (env_cdpath == NULL)
		return (chdir(str));
	cdpath = ft_split(env_cdpath->value, ':');
	if (cdpath == NULL)
		return (CD_MALLOC_ERR);
	idx = 0;
	while (cdpath[idx] != NULL)
	{
		if (chdir(ft_strjoin(cdpath[idx++], str)) == CD_SUCCESS)
		{
			ft_putendl_fd(getcwd(NULL, 0), STDOUT_FILENO);
			free_char_list(cdpath);
			return (CD_SUCCESS);
		}
	}
	free_char_list(cdpath);
	return (chdir(str));
}

static void	cd_normal(t_data *data, char *str)
{
	int	return_number;

	if (ft_strncmp(str, "/", 1) == 0 || ft_strncmp(str, "./", 2) == 0)
		return_number = chdir(str);
	else if (ft_strncmp(str, "../", 3) == 0)
		return_number = chdir(str);
	else
		return_number = chdir_with_cdpath(data->env_map, str);
	if (return_number == CD_SUCCESS)
		change_pwd_oldpwd_crrdir(data, false);
	else if (return_number == CD_FAILD && *str == '\0')
		change_pwd_oldpwd_crrdir(data, true);
	else if (return_number == CD_FAILD)
		err_no_cd_file(str, &data->err_code);
	else if (return_number == CD_MALLOC_ERR)
		data->err_code = 0;
}

static void	cd_home_dir(t_data *data)
{
	t_env	*env_home;

	env_home = select_env(data->env_map, "HOME");
	if (env_home == NULL || env_home->value == NULL)
		err_no_home(&data->err_code);
	else if (*env_home->value == '\0')
		change_pwd_oldpwd_crrdir(data, true);
	else
		cd_normal(data, env_home->value);
}

void	my_cd(t_words *word_list, int fd, t_data *data)
{
	if (fd != STDOUT_FILENO)
	{
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	if (word_list != NULL && ft_strcmp(word_list->word, "--") == 0)
		word_list = word_list->next;
	if (word_list == NULL)
		cd_home_dir(data);
	else if (word_list->next != NULL)
		err_many_arg("cd", &data->err_code);
	else
		cd_normal(data, word_list->word);
}
