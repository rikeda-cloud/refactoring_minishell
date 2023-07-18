#include "../../include/minishell.h"

static void	ft_strcat_const(char *dest, char const *src)
{
	while (*dest != '\0')
		dest++;
	while (*src != '\0')
		*dest++ = *src++;
	*dest = '\0';
}

static char	*strjoin_single_case(char const *s1, char const *s2)
{
	char	*tmp_ptr;
	char	*not_null_str;
	size_t	len;

	if (s1 != NULL)
		not_null_str = (char *)s1;
	else
		not_null_str = (char *)s2;
	len = ft_strlen(not_null_str);
	tmp_ptr = (char *)ft_calloc(sizeof(char), len + 1);
	if (tmp_ptr == NULL)
		return (NULL);
	ft_strcat_const(tmp_ptr, not_null_str);
	return (tmp_ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*tmp_ptr;

	if (s1 == NULL && s2 == NULL)
	{
		tmp_ptr = (char *)ft_calloc(sizeof(char), 1);
		if (tmp_ptr == NULL)
			return (NULL);
	}
	else if (s1 == NULL || s2 == NULL)
		tmp_ptr = strjoin_single_case(s1, s2);
	else
	{
		len = ft_strlen(s1);
		len += ft_strlen(s2);
		tmp_ptr = (char *)ft_calloc(len + 1, sizeof(char));
		if (tmp_ptr == NULL)
			return (NULL);
		ft_strcat_const(tmp_ptr, s1);
		ft_strcat_const(tmp_ptr, s2);
	}
	return (tmp_ptr);
}
