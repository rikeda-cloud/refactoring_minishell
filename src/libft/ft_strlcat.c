#include "../../include/minishell.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	limit;

	if (dstsize == 0)
		return (ft_strlen(src));
	len = ft_strlen(dst);
	if (len >= dstsize)
		return (dstsize + ft_strlen(src));
	limit = dstsize - len -1;
	len += ft_strlen(src);
	while (*dst != '\0')
		dst++;
	while (*src != '\0' && limit)
	{
		*dst++ = *src++;
		limit--;
	}
	*dst = '\0';
	return (len);
}
