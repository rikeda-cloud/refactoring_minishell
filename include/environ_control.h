/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ_control.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:56:46 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/12 12:50:13 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRON_CONTROL_H
# define ENVIRON_CONTROL_H

# include "define.h"

t_env	**change_environ_to_map(const char **environ, char *crr_dir);
char	**change_map_to_environ(t_env **map, bool *err_flag);

t_env	*select_env(t_env **map, const char *env_name);
bool	update_env(t_env **map, const char *name, const char *new_value);
bool	delete_env(t_env **map, const char *env_name);
t_env	*insert_env_to_env_map(t_env **map, char *original);

void	insert_or_update_env(char *word, t_data *data);

#endif
