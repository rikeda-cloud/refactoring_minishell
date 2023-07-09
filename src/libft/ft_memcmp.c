#include "../../include/minishell.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*tmp_s1;
	unsigned char	*tmp_s2;

	if (n == 0)
		return (0);
	tmp_s1 = (unsigned char *)s1;
	tmp_s2 = (unsigned char *)s2;
	while (n-- > 0)
	{
		if (*tmp_s1 != *tmp_s2)
			return ((int)*tmp_s1 - *tmp_s2);
		tmp_s1++;
		tmp_s2++;
	}
	return (0);
}
