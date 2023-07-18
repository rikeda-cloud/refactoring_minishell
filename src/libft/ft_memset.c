#include "../../include/minishell.h" 

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp_s;

	tmp_s = (unsigned char *)b;
	while (len--)
		*tmp_s++ = c;
	return (b);
}
