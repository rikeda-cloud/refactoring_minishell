#include "../../include/minishell.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*tmp_dest;
	const unsigned char	*tmp_src;

	if (dst == NULL && src == NULL)
		return (dst);
	tmp_dest = (unsigned char *)dst;
	tmp_src = (const unsigned char *)src;
	while (n-- > 0)
		*tmp_dest++ = *tmp_src++;
	return (dst);
}
