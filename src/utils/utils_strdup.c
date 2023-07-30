#include "../../include/minishell.h"

char	*strdup_n(const char *src, size_t n)
{
	size_t	idx;
	char	*dest;

	idx = 0;
	dest = (char *)calloc(sizeof(char), (n + 1));
	while (idx < n)
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (dest);
}

char	*strdup_env(const char *str, bool *err_flag)
{
	const char	*env_position;
	char		*env;

	if (str == NULL)
		return (NULL);
	env_position = get_env_position(str);
	if (*env_position == '\0')
		return (NULL);
	env = strdup_n(&env_position[1], count_env_size(env_position));
	if (env == NULL)
		return (reverse_flag(err_flag));
	return (env);
}
