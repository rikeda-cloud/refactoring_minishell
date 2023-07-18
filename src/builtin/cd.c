#include "../../include/minishell.h"

void	cd_home_dir_pattern()
{
	t_env	*home_dir_env;
	int		chdir_return_value;

	home_dir_env = select_env(data.env_map, "HOME");
	if (home_dir_env == NULL)
		printf(FMT_ERR_NO_HOME);
	else
	{
		if (*home_dir_env->value != '\0')
		{
			chdir_return_value = chdir(home_dir_env->value);
			if (chdir_return_value != 0)
				printf(FMT_ERR_NO_FILE, home_dir_env->value);
			else
				data.crr_dir = getcwd(NULL, 0);
		}
	}
}

void	cd_normal_pattern(char *str)
{
	int	chdir_return_value;

	if (*str != '\0')
	{
		chdir_return_value = chdir(str);
		if (chdir_return_value != 0)
			printf(FMT_ERR_NO_FILE, str);
		else
			data.crr_dir = getcwd(NULL, 0);
	}
}

void	my_cd(t_words *word_list, int fd)
{
	if (fd != STDOUT_FILENO)
	{
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	if (word_list == NULL)
		cd_home_dir_pattern();
	else if (word_list->next != NULL)
		printf(FMT_ERR_MANY_ARG_CD);
	else
		cd_normal_pattern(word_list->word);
}
