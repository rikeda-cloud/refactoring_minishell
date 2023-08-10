/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_environ_to_map.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:57:52 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/06 14:57:53 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static bool	curd_oldpwd(t_env **map)
{
	t_env	*env_pwd;
	char	*oldpwd;

	env_pwd = select_env(map, "OLDPWD");
	if (env_pwd == NULL)
	{
		oldpwd = ft_strdup("OLDPWD");
		if (oldpwd == NULL)
			return (true);
		else if (insert_env_to_env_map(map, oldpwd) == NULL)
			return (true);
	}
	else if (env_pwd->value == NULL)
		;
	else if (access(env_pwd->value, X_OK) != 0)
		env_pwd->value = free_str(env_pwd->value);
	return (false);
}

static bool	curd_pwd(t_env **map, char *crr_dir)
{
	t_env	*env_pwd;
	char	*original_pwd;

	if (crr_dir == NULL)
		return (true);
	env_pwd = select_env(map, "PWD");
	if (env_pwd == NULL)
	{
		original_pwd = ft_strjoin("PWD=", crr_dir);
		if (original_pwd == NULL)
			return (true);
		else if (insert_env_to_env_map(map, original_pwd))
			return (true);
	}
	else
		update_env(map, "PWD", crr_dir);
	return (false);
}

t_env	**change_environ_to_map(const char **environ, char *crr_dir)
{
	t_env	**map;
	size_t	idx;

	if (environ == NULL)
		return (NULL);
	map = (t_env **)ft_calloc(sizeof(t_env *), HASH_MAP_SIZE);
	if (map == NULL)
		return (NULL);
	idx = 0;
	while (environ[idx] != NULL)
	{
		if (insert_env_to_env_map(map, ft_strdup(environ[idx++])) == NULL)
			return (free_hash_map(map));
	}
	if (curd_oldpwd(map) || curd_pwd(map, crr_dir))
		return (free_hash_map(map));
	return (map);
}
