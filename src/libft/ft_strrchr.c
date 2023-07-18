#include "../../include/minishell.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	char	tmp_c;

	tmp_c = (char)c;
	if (tmp_c == '\0')
	{
		while (*s != '\0')
			s++;
		return ((char *)s);
	}
	tmp = NULL;
	while (*s != '\0')
	{
		if (*s == tmp_c)
			tmp = (char *)s;
		s++;
	}
	return (tmp);
}
