#include "../../include/minishell.h"

static void	join_env_to_env_ary(char **ary, t_env *hash_list, bool (f)(char *))
{
	size_t	idx;

	idx = 0;
	while (ary[idx] != NULL)
		idx++;
	while (hash_list != NULL)
	{
		if (f(hash_list->value) == true)
		{
			ary[idx] = hash_list->original;
			idx++;
		}
		hash_list = hash_list->next;
	}
}

char	**change_map_to_environ(t_env **map, size_t size, bool (f)(char *))
{
	char	**env_ary;
	size_t	idx;

	env_ary = (char **)ft_calloc(sizeof(char *), (size + 1));
	if (env_ary == NULL)
		return (NULL);
	idx = 0;
	while (idx < HASH_MAP_SIZE)
		join_env_to_env_ary(env_ary, map[idx++], f);
	return (env_ary);
}
