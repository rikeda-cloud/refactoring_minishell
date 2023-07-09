#include "../../include/minishell.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*tmp_dest;
	unsigned char const	*tmp_src;

	if (dst <= src)
		ft_memcpy(dst, src, len);
	else
	{
		tmp_dest = (unsigned char *)dst;
		tmp_dest += len;
		tmp_src = (unsigned char const *)src;
		tmp_src += len;
		while (len-- > 0)
			*--tmp_dest = *--tmp_src;
	}
	return (dst);
}
