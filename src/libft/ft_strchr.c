#include "../../include/minishell.h"

int	ft_strchr_asaka( const  char *s, int c)
{
	if ((char)c == '\0')
		return (1);
	while (s != NULL && *s != '\0')
	{
		if (*s++ == (char)c)
			return (1);
	}
	return (0);
}

char	*ft_strchr( const  char *s, int c)
{
	char	tmp_c;

	tmp_c = (char)c;
	if (tmp_c == '\0')
	{
		while (*s != '\0')
			s++;
		return ((char *)s);
	}
	else
	{
		while (*s != '\0')
		{
			if (*s == tmp_c)
				return ((char *)s);
			s++;
		}
	}
	return (NULL);
}
