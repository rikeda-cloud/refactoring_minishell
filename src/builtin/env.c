#include "../../include/minishell.h"

void	join_word_to_env_environ(char **env_environ, t_words *word_list)
{
	size_t	idx;

	idx = 0;
	while (env_environ[idx] != NULL)
		idx++;
	while (word_list != NULL)
	{
		if (is_in_equal(word_list->word))
			env_environ[idx++] = word_list->word;
		word_list = word_list->next;
	}
}

char	**get_env_pattern_environ(t_words *word_list, t_env **map)
{
	size_t	environ_size;
	char	**env_environ;

	environ_size = count_map_size(map, is_null);
	environ_size += count_assignment_word(word_list);
	env_environ = change_map_to_environ(map, environ_size, is_null);
	if (env_environ == NULL)
		return (NULL);
	join_word_to_env_environ(env_environ, word_list);
	return (env_environ);
}

void	my_env(t_words *word_list, int fd, t_data *data)
{
	char	**env;

	if (fd != STDOUT_FILENO)
	{
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	env = get_env_pattern_environ(word_list, data->env_map);
	if (env != NULL)
		/* data->return_code = execve("COMMANDPATH", "-la", env); */;
}
