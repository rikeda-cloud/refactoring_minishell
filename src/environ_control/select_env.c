#include "../../include/minishell.h"

t_env	*select_env(t_env **map, char *env_name)
{
	t_env	*env_list;

	if (map == NULL)
		return (NULL);
	env_list =  map[hash(*env_name)];	
	while (env_list != NULL)
	{
		if (ft_strcmp(env_name, env_list->name) == 0)
			return (env_list);
		env_list = env_list->next;
	}
	return (NULL);
}
