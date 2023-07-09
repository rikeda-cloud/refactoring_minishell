#include "../../include/minishell.h"

void	insert_env_to_env_map(t_env **map, char *env)
{
	t_env	*new_env;
	int		hash_value;

	hash_value = hash(*env);
	new_env = (t_env *)calloc(sizeof(t_env), 1);
	new_env->name = strdup_n(env, count_to_front_of_c(env, '='));
	while (*env != '=')
		env++;
	env++;
	new_env->value = strdup_n(env, count_to_front_of_c(env, '\0'));
	insert_new_env(map, new_env, hash_value);
}
