#include "../../include/minishell.h"

void	attach_env_original_to_env_ary(char **env_ary, t_env *hash_list)
{
	size_t	idx;

	idx = 0;
	while (env_ary[idx] != NULL)
		idx++;
	while (hash_list != NULL)
	{
		env_ary[idx] = hash_list->original;
		idx++;
		hash_list = hash_list->next;
	}
}

char	**change_hash_map_to_environ(t_env **map)
{
	char	**env_ary;
	size_t	idx;

	env_ary = (char **)ft_calloc(sizeof(char *), count_map_size(map) + 1);
	if (env_ary == NULL)
		return (NULL);
	idx = 0;
	while (idx < HASH_MAP_SIZE)
		attach_env_original_to_env_ary(env_ary, map[idx++]);
	return (env_ary);
}
