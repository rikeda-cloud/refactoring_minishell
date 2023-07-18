#include "../../include/minishell.h"

t_env	**change_env_to_hash_map(void)
{
	extern char	**environ;
	t_env		**map;

	map = (t_env **)calloc(sizeof(t_env *), HASH_MAP_SIZE);
	if (map == NULL)
		return (NULL);
	while (*environ != NULL)
		insert_env_to_env_map(map, *environ++);
	return (map);
}
