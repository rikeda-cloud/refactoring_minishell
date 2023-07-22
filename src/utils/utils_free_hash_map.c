#include "../../include/minishell.h"

void	*free_env(t_env *env)
{
	if (env == NULL)
		return (NULL);
	if (env->name != NULL)
		free(env->name);
	if (env->value!= NULL)
		free(env->value);
	free(env);
	return (NULL);
}

static void	*free_hash_list(t_env *hash_list)
{
	t_env	*tmp;

	while (hash_list != NULL)
	{
		tmp = hash_list;
		hash_list = hash_list->next;
		free_env(tmp);
	}
	return (NULL);
}

void	*free_hash_map(t_env **hash_map)
{
	size_t	idx;

	idx = 0;
	while (idx < HASH_MAP_SIZE)
		free_hash_list(hash_map[idx++]);
	return (NULL);
}
