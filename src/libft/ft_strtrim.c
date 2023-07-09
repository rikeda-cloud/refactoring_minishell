#include "../../include/minishell.h"
#include <stdlib.h>

static bool	is_s1_in_set(char const s1, char const *set)
{
	while (*set != '\0')
	{
		if (s1 == *set++)
			return (true);
	}
	return (false);
}

static int	trimlen_count(char const *s1, char const *set, int s1_len)
{
	int	counter;
	int	tmp_s1_len;

	counter = 0;
	tmp_s1_len = s1_len - 1;
	while (s1[counter] != '\0')
	{
		if (is_s1_in_set(s1[counter], set) == false)
			break ;
		counter++;
	}
	while (tmp_s1_len >= 0)
	{
		if (is_s1_in_set(s1[tmp_s1_len], set) == false)
			break ;
		counter++;
		tmp_s1_len--;
	}
	if (s1_len <= counter)
		return (0);
	else
		return (counter);
}

static void	fill_ptr(char *p, char const *s1, char const *set, int size)
{
	if (size == 1)
		*p = '\0';
	else
	{
		while (*s1 != '\0')
		{
			if (is_s1_in_set(*s1++, set) == false)
				break ;
		}
		while (size-- > 1)
			*p++ = *s1++;
		*p = '\0';
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		s1_len;
	char	*ptr;
	int		new_str_size;

	if (s1 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	if (set == NULL)
		new_str_size = s1_len + 1;
	else
		new_str_size = s1_len - trimlen_count(s1, set, s1_len) + 1;
	ptr = (char *)ft_calloc(sizeof(char), new_str_size);
	if (ptr == NULL)
		return (NULL);
	fill_ptr(ptr, s1, set, new_str_size);
	return (ptr);
}
