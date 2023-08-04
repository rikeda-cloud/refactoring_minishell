#include "../../include/minishell.h"

static void	insert_new_env(t_env **map, t_env *new_env, int hash_value)
{
	t_env	*top_env;

	top_env = map[hash_value];
	if (top_env == NULL || ft_strcmp(new_env->name, top_env->name) < 0)
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

t_env	*new_new_env(char *original)
{
	t_env	*new_env;

	new_env = (t_env *)ft_calloc(sizeof(t_env), 1);
	if (new_env == NULL)
		return (NULL);
	new_env->original = original;
	new_env->name = strdup_n(original, count_to_front_of_c(original, '='));
	if (new_env->name == NULL)
		return (free_env(new_env));
	while (*original != '\0' && *original != '=')
		original++;
	if (*original == '\0')
		return (new_env);
	original++;
	new_env->value = strdup_n(original, count_to_front_of_c(original, '\0'));
	if (new_env->value == NULL)
		return (free_env(new_env));
	return (new_env);
}

t_env	*insert_env_to_env_map(t_env **map, char *original)
{
	t_env	*new_env;
	int		hash_value;

	if (map == NULL || original == NULL)
		return (NULL);
	hash_value = hash(*original);
	new_env = new_new_env(original);
	if (new_env == NULL)
		return (NULL);
	insert_new_env(map, new_env, hash_value);
	return (new_env);
}
