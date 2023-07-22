#include "../../include/minishell.h"

t_env	**change_environ_to_hash_map(void)
{
	extern char	**environ;
	t_env		**map;

	map = (t_env **)calloc(sizeof(t_env *), HASH_MAP_SIZE);
	if (map == NULL)
		return (NULL);
	while (*environ != NULL)
	{
		if (insert_env_to_env_map(map, ft_strdup(*environ++)) == NULL)
			return (free_hash_map(map));
	}
	return (map);
}
