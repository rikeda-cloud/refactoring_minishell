#include "../../include/minishell.h"

char	*ft_strcat(char *dst, const char *src)
{
	char	*dst_top_ptr;

	if (dst == NULL)
		return (NULL);
	else if (src == NULL)
		return (dst);
	dst_top_ptr = dst;
	while (*dst != '\0')
		dst++;
	while (*src != '\0')
		*dst++ = *src++;
	return (dst_top_ptr);
}
