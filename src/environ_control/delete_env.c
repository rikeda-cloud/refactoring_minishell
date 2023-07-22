#include "../../include/minishell.h"

static t_env	*del_env_node(t_env *env)
{
	t_env	*next_node;

	if (env == NULL)
		return (NULL);
	next_node = env->next;
	if (env->name != NULL)
		free(env->name);
	if (env->value != NULL)
		free(env->value);
	if (env->original != NULL)
		free(env->original);
	free(env);
	return (next_node);
}

static t_env	*del_top_env(t_env *env_list)
{
	return (del_env_node(env_list));
}

static void	del_middle_env(t_env *env_list, char *env_name)
{
	t_env	*prev_env;

	prev_env = env_list;
	env_list = env_list->next;
	while (env_list != NULL)
	{
		if (ft_strcmp(env_list->name, env_name) == 0)
		{
			prev_env->next = del_env_node(env_list);
			break ;
		}
		prev_env = env_list;
		env_list = env_list->next;
	}
}

bool	delete_env(t_env **map, char *env_name)
{
	int	hash_value;

	if (map == NULL || select_env(map, env_name) == NULL)
		return (false);
	hash_value = hash(*env_name);
	if (ft_strcmp(map[hash_value]->name, env_name) == 0)
		map[hash_value] = del_top_env(map[hash_value]);
	else
		del_middle_env(map[hash_value], env_name);
	return (true);
}
