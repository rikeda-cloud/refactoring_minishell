#ifndef ENVIRON_CONTROL_H
#define ENVIRON_CONTROL_H

#include "define.h"

t_env	**change_environ_to_hash_map(void);
char	**change_hash_map_to_environ(t_env **map);
void	insert_new_env(t_env **map, t_env *new_env, int hash_value);
t_env	*insert_env_to_env_map(t_env **map, char *original);
t_env	*select_env(t_env **map, char *env_name);
bool	update_env(t_env **map, char *env_name, char *new_env_value);
bool	delete_env(t_env **map, char *env_name);

#endif
