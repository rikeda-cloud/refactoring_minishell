#include "../../include/minishell.h"

/* static size_t	count_hash_list_size(t_env *hash_list) */
/* { */
/* 	size_t	size; */

/* 	size = 0; */
/* 	while (hash_list != NULL) */
/* 	{ */
/* 		if (hash_list->value != NULL) */
/* 			size++; */
/* 		hash_list = hash_list->next; */
/* 	} */
/* 	return (size); */
/* } */

/* size_t	count_map_size(t_env **map) */
/* { */
/* 	size_t	idx; */
/* 	size_t	size; */

/* 	idx = 0; */
/* 	size = 0; */
/* 	while (idx < HASH_MAP_SIZE) */
/* 		size += count_hash_list_size(map[idx++]); */
/* 	return (size); */
/* } */

/* static void	join_env_to_env_ary(char **ary, t_env *hash_list) */
/* { */
/* 	size_t	idx; */

/* 	idx = 0; */
/* 	while (ary[idx] != NULL) */
/* 		idx++; */
/* 	while (hash_list != NULL) */
/* 	{ */
/* 		if (hash_list->value != NULL) */
/* 			ary[idx++] = hash_list->original; */
/* 		hash_list = hash_list->next; */
/* 	} */
/* } */

/* char	**change_map_to_environ(t_env **map) */
/* { */
/* 	size_t	map_size; */
/* 	char	**env_ary; */
/* 	size_t	idx; */

/* 	map_size = count_map_size(map); */
/* 	env_ary = (char **)ft_calloc(sizeof(char *), (map_size + 1)); */
/* 	if (env_ary == NULL) */
/* 		return (NULL); */
/* 	idx = 0; */
/* 	while (idx < HASH_MAP_SIZE) */
/* 		join_env_to_env_ary(env_ary, map[idx++]); */
/* 	return (env_ary); */
/* } */

void	my_env(t_words *word_list, int fd, t_data *data)
{
	char	**env;

	if (fd != STDOUT_FILENO)
	{
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	while (word_list != NULL && is_in_equal(word_list->word))
	{
		insert_or_update_env(word_list->word, data);
		word_list = word_list->next;
	}
	env = change_map_to_environ(data->env_map);
	if (env == NULL)
		return ;
	if (word_list == NULL)
		print_all_env(fmt_env, STDOUT_FILENO, data);
	/* else */
		/* execve("", "", env); */
}
