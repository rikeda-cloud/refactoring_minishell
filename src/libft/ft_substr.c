#include "../../include/minishell.h"

static size_t	min_size_t(size_t a, size_t b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

static char	*fill_ptr(char const *s, size_t len)
{
	char	*ptr;
	char	*tmp_ptr;

	ptr = (char *)ft_calloc(sizeof(char), len + 1);
	if (ptr == NULL)
		return (NULL);
	tmp_ptr = ptr;
	while (len-- > 0)
		*ptr++ = *s++;
	*ptr = '\0';
	return (tmp_ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;

	if (s == NULL)
		return (NULL);
	while (start-- > 0 && *s != '\0')
		s++;
	if (*s == '\0')
		ptr = (char *)ft_calloc(sizeof(char), 1);
	else
		ptr = fill_ptr(s, min_size_t(ft_strlen(s), len));
	return (ptr);
}
