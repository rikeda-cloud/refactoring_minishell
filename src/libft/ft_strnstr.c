#include "../../include/minishell.h"

static bool	is_needle_in_hayastack(char *big, char *little, int n)
{
	while (n-- && *big++ == *little)
	{
		if (*little++ == '\0')
			return (true);
	}
	if (*little == '\0')
		return (true);
	return (false);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (*needle == '\0')
		return ((char *)haystack);
	while (len > 0 && *haystack != '\0')
	{
		if (*haystack == *needle)
		{
			if (is_needle_in_hayastack((char *)haystack, (char *)needle, len))
				return ((char *)haystack);
		}
		haystack++;
		len--;
	}
	return (NULL);
}
