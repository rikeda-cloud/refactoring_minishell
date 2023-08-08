/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:58:33 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/06 14:58:34 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	exec_builtin_cmd_child_proc(t_words *word_list, t_data *data)
{
	do_builtin_cmd(word_list, data, true);
	exit(data->err_code);
}

void	exec_normal_cmd_child_proc(t_words *word_list, t_data *data)
{
	char	**separgv;
	char	**my_environ;
	char	*path;

	if (word_list == NULL)
		exit(0);
	separgv = change_word_list_to_cmd(word_list);
	if (separgv == NULL)
		exit(1);
	path = get_path(separgv[0], data);
	if (path == NULL)
		exit(1);
	my_environ = change_map_to_environ(data->env_map, &data->err_flag);
	if (data->err_flag)
		exit(1);
	do_execve(path, separgv, my_environ);
}
