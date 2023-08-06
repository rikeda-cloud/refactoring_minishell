#include "../../include/minishell.h"

static void	join_env_to_env_ary(char **ary, t_env *hash_list)
{
	size_t	idx;

	idx = 0;
	while (ary[idx] != NULL)
		idx++;
	while (hash_list != NULL)
	{
		if (hash_list->value != NULL)
			ary[idx++] = hash_list->original;
		hash_list = hash_list->next;
	}
}

char	**change_map_to_environ(t_env **map, bool *err_flag)
{
	size_t	map_size;
	char	**env_ary;
	size_t	idx;

	if (map == NULL)
		return (NULL);
	map_size = count_map_size(map);
	env_ary = (char **)ft_calloc(sizeof(char *), (map_size + 1));
	if (env_ary == NULL)
	{
		*err_flag = true;
		return (NULL);
	}
	idx = 0;
	while (idx < HASH_MAP_SIZE)
		join_env_to_env_ary(env_ary, map[idx++]);
	return (env_ary);
}
