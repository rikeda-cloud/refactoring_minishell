#include "../../include/minishell.h"

void	cd_home_dir_pattern(t_data *data)
{
	t_env	*env_home;
	int		chdir_return_value;

	env_home = select_env(data->env_map, "HOME");
	if (env_home == NULL)
		err_no_home(&data->err_code);
	else
	{
		if (*env_home->value != '\0')
		{
			chdir_return_value = chdir(env_home->value);
			if (chdir_return_value != 0)
				err_no_file(env_home->value, &data->err_code);
			else
			{
				data->crr_dir = getcwd(NULL, 0);
				data->err_code = 0;
			}
		}
	}
}

void	cd_normal_pattern(char *str, t_data *data)
{
	int	chdir_return_value;

	if (*str != '\0')
	{
		chdir_return_value = chdir(str);
		if (chdir_return_value != 0)
			err_no_file(str, &data->err_code);
		else
			data->crr_dir = getcwd(NULL, 0);
	}
	else
		data->err_code = 0;
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
		cd_home_dir_pattern(data);
	else if (word_list->next != NULL)
		err_many_arg("cd", &data->err_code);
	else
		cd_normal_pattern(word_list->word, data);
}
