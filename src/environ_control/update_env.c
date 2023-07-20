#include "../../include/minishell.h"

bool	update_env(t_env **map, char *env_name, char *new_env_value)
{
	t_env	*target_env;

	target_env = select_env(map, env_name);
	if (target_env == NULL)
		return (false);
	if (target_env->value != NULL)
		free(target_env->value);
	target_env->value = ft_strdup(new_env_value);
	if (target_env->value == NULL)
		return (false);
	return (true);
}
