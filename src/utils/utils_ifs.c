#include "../../include/minishell.h"

bool	is_ifs(int c)
{
	const char	*ifs_chars;
	t_env		*env_ifs;

	env_ifs = select_env(data.env_map, "IFS");
	if (env_ifs == NULL)
		ifs_chars = IFS_CHARS;
	else
		ifs_chars = env_ifs->value;
	while (*ifs_chars != '\0')
	{
		if (*ifs_chars++ == c)
			return (true);
	}
	return (false);
}

bool	is_in_ifs_char(const char *str)
{
	if (str == NULL)
		return (false);
	while (*str != '\0')
	{
		if (is_ifs(*str++))
			return (true);
	}
	return (false);
}

size_t	strlen_ifs(const char *str)
{
	size_t	size;

	size = 0;
	while (str[size] != '\0' && is_ifs(str[size]))
		size++;
	return (size);
}

size_t	strlen_to_ifs(const char *str)
{
	size_t	size;

	size = 0;
	while (str[size] != '\0' && is_ifs(str[size]) == false)
		size++;
	return (size);
}
