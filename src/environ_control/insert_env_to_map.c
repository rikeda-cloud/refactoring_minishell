#include "../../include/minishell.h"

t_env	*insert_env_to_env_map(t_env **map, char *env)
{
	t_env	*new_env;
	int		hash_value;

	hash_value = hash(*env);
	new_env = (t_env *)calloc(sizeof(t_env), 1);
	if (new_env == NULL)
		return (NULL);
	new_env->name = strdup_n(env, count_to_front_of_c(env, '='));
	if (new_env->name == NULL)
		return (free_env(new_env));
	while (*env != '\0' && *env != '=')
		env++;
	if (*env == '\0')
		return (new_env);
	env++;
	new_env->value = strdup_n(env, count_to_front_of_c(env, '\0'));
	if (new_env->value == NULL)
		return (free_env(new_env));
	insert_new_env(map, new_env, hash_value);
	return (new_env);
}
