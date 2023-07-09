#include "../../include/minishell.h"

char	*ft_strdup(const char *s1)
{
	char				*ptr;
	char				*tmp_ptr;

	if (s1 == NULL)
		return (NULL);
	ptr = (char *)ft_calloc(sizeof(char), ft_strlen(s1) + 1);
	if (ptr == NULL)
		return (NULL);
	tmp_ptr = ptr;
	while (*s1 != '\0')
		*ptr++ = *s1++;
	*ptr = '\0';
	return (tmp_ptr);
}
