#include "../../include/minishell.h"

void	insert_new_env(t_env **map, t_env *new_env, int hash_value)
{
	t_env	*top_env;

	top_env = map[hash_value];
	if (top_env == NULL)
		map[hash_value] = new_env;
	else if (ft_strcmp(new_env->name, top_env->name) < 0)
	{
		new_env->next = top_env;
		map[hash_value] = new_env;
	}
	else
	{
		while (top_env->next != NULL)
		{
			if (ft_strcmp(new_env->name, top_env->next->name) < 0)
				break ;
			top_env = top_env->next;
		}
		new_env->next = top_env->next;
		top_env->next = new_env;
	}
}
