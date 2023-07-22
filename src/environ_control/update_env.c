#include "../../include/minishell.h"

char	*new_new_original(const char *name, const char *value)
{
	size_t	size;
	size_t	idx;
	char	*new_original;

	size = ft_strlen(name) + ft_strlen(value) + 1;
	new_original = (char *)ft_calloc(sizeof(char), (size + 1));
	if (new_original == NULL)
		return (NULL);
	idx = 0;
	while (*name != '\0')
		new_original[idx++] = *name++;
	new_original[idx++] = '=';
	while (*value != '\0')
		new_original[idx++] = *value++;
	return (new_original);
}

bool	update_env(t_env **map, char *name, char *new_value)
{
	t_env	*target_env;

	if (map == NULL)
		return (false);
	target_env = select_env(map, name);
	if (target_env == NULL)
		return (true);
	if (target_env->original != NULL)
		free(target_env->original);
	if (target_env->value != NULL)
		free(target_env->value);
	target_env->original = new_new_original(name, new_value);
	target_env->value = ft_strdup(new_value);
	if (target_env->original == NULL || target_env->value == NULL)
	{
		delete_env(map, name);
		return (false);
	}
	return (true);
}
