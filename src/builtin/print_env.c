#include "../../include/minishell.h"

void	print_env(void (*fmt)(char *, char *, int), t_env *env, int fd)
{
	fmt(env->name, env->value, fd);
}

void	print_hash_upper(t_env *env, void (*fmt)(char *,char *, int), int fd)
{
	while (env != NULL)
	{
		if (ft_islower(*env->name))
			break ;
		print_env(fmt, env, fd);
		env = env->next;
	}
}

void	print_hash_lower(t_env *env, void (*fmt)(char *,char *, int), int fd)
{
	while (env != NULL)
	{
		if (ft_isupper(*env->name) == 0)
			print_env(fmt, env, fd);
		env = env->next;
	}
}

void	print_all_env(void (*fmt)(char *,char *,int), int fd, t_data *data)
{
	size_t	hash_number;

	hash_number = 1;
	while (hash_number < HASH_MAP_SIZE)
		print_hash_upper(data->env_map[hash_number++], fmt, fd);
	hash_number = 0;
	while (hash_number < HASH_MAP_SIZE)
		print_hash_lower(data->env_map[hash_number++], fmt, fd);
}
