#include "../../include/minishell.h"

static char	*new_new_word(char *str, char *target, const char *new_word)
{
	size_t		new_str_size;
	char		*new_str;
	const char	*env_position;
	
	new_str_size = ft_strlen(str) + ft_strlen(new_word) - ft_strlen(target);
	new_str = (char *)ft_calloc(sizeof(char), (new_str_size));
	if (new_str == NULL)
		return (NULL);
	env_position = get_env_position(str);
	ft_strlcat(new_str, str, (env_position - str + 1));
	ft_strcat(new_str, new_word);
	env_position += (ft_strlen(target) + 1);
	ft_strcat(new_str, env_position);
	return (new_str);
}

char	*replace(char *str, char *target, const char *new_word)
{
	char	*new_str;

	new_str = new_new_word(str, target, new_word);
	free_str(str);
	free_str(target);
	return (new_str);
}
