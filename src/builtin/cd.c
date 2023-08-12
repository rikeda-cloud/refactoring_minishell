/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:57:15 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/12 12:50:35 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	update_oldpwd(t_env **map)
{
	t_env	*env_pwd;
	t_env	*env_oldpwd;

	if (map == NULL)
		return ;
	env_pwd = select_env(map, "PWD");
	env_oldpwd = select_env(map, "OLDPWD");
	if (env_oldpwd == NULL)
		return ;
	else if (env_pwd == NULL || env_pwd->value == NULL)
		env_oldpwd->value = free_str(env_oldpwd->value);
	else
		update_env(map, "OLDPWD", env_pwd->value);
}

static void	change_pwd_oldpwd_crrdir(t_data *data, char *str)
{
	char	*new_crr_dir;

	data->err_code = 0;
	new_crr_dir = getcwd(NULL, 0);
	if (new_crr_dir == NULL && str[0] == '\0')
		err_no_cd_file("", &data->err_code);
	else
	{
		update_oldpwd(data->env_map);
		update_env(data->env_map, "OLDPWD", data->crr_dir);
		if (new_crr_dir == NULL)
		{
			print_err3(ERR_RETRIEVING, ERR_GETCWD, ERR_NO_FILE_CLOSE);
			new_crr_dir = strjoin_path_auto_adjustment(data->crr_dir, str);
		}
		if (new_crr_dir == NULL)
			data->err_code = 1;
		data->crr_dir = free_str(data->crr_dir);
		data->crr_dir = new_crr_dir;
	}
	update_env(data->env_map, "PWD", data->crr_dir);
}

static void	cd_normal(t_data *data, char *str)
{
	t_cd	cd_mode;

	cd_mode = CD_NO_FILE;
	if (ft_strncmp(str, "/", 1) == 0 || ft_strncmp(str, "./", 2) == 0)
		cd_mode = try_chdir(str, &cd_mode);
	else if (ft_strcmp(str, "..") == 0 || ft_strncmp(str, "../", 3) == 0)
		cd_mode = try_chdir(str, &cd_mode);
	else
		cd_mode = try_chdir_with_cdpath(data->env_map, str);
	if (cd_mode == CD_SUCCESS)
		change_pwd_oldpwd_crrdir(data, str);
	else if (cd_mode == CD_MALLOC_ERR)
		data->err_code = 1;
	else if (cd_mode == CD_NO_PERMISSION)
		err_no_permission(str, &data->err_code);
	else if (cd_mode == CD_NO_FILE && *str == '\0')
		change_pwd_oldpwd_crrdir(data, "");
	else if (cd_mode == CD_NO_FILE)
		err_no_cd_file(str, &data->err_code);
}

static void	cd_home_dir(t_data *data)
{
	t_env	*env_home;

	env_home = select_env(data->env_map, "HOME");
	if (env_home == NULL || env_home->value == NULL)
		err_no_home(&data->err_code);
	else
		cd_normal(data, env_home->value);
}

void	my_cd(t_words *word_list, int fd, t_data *data, bool exit_flag)
{
	dup2_and_close_stdout(fd, exit_flag, &data->err_flag);
	if (data->err_flag)
	{
		data->err_code = 1;
		return ;
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
