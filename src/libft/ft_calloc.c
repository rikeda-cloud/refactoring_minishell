#include "../../include/minishell.h"

void	*ft_calloc(size_t count, size_t size)
{
	char			*ptr;
	size_t			memory_size;

	if (count == 0 || size == 0)
		ft_calloc(1, 1);
	else if ((size_t)SIZE_MAX / size < count)
		return (NULL);
	memory_size = count * size;
	ptr = (char *)malloc(memory_size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, memory_size);
	return ((void *)ptr);
}
