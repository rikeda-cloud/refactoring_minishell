#include "../../include/minishell.h"

t_env	**change_environ_to_map(const char **environ)
{
	t_env	**map;
	size_t	idx;

	map = (t_env **)ft_calloc(sizeof(t_env *), HASH_MAP_SIZE);
	if (map == NULL)
		return (NULL);
	idx = 0;
	while (environ[idx] != NULL)
	{
		if (insert_env_to_env_map(map, ft_strdup(environ[idx++])) == NULL)
			return (free_hash_map(map));
	}
	return (map);
}
