#include "../../include/minishell.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp_s;
	unsigned char	tmp_c;

	tmp_s = (unsigned char *)s;
	tmp_c = (unsigned char)c;
	while (n-- > 0)
	{
		if (*tmp_s == tmp_c)
			return ((void *)tmp_s);
		tmp_s++;
	}
	return (NULL);
}
