#include "../../include/minishell.h"

static size_t	sp_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (*str != '\0' && *str != '\n')
	{
		len++;
		str++;
	}
	if (*str == '\n')
		len++;
	return (len);
}

static void	sp_strcat(char *dest, char *src)
{
	while (*dest != '\0')
		dest++;
	while (*src != '\0' && *src != '\n')
		*dest++ = *src++;
	if (*src == '\n')
		*dest++ = *src;
	*dest = '\0';
}

static char	*sp_join_single_case(char *dest, char *src)
{
	char	*new_str;
	char	*not_null_str;

	if (dest != NULL)
		not_null_str = dest;
	else
		not_null_str = src;
	new_str = (char *)ft_calloc(sizeof(char), (sp_strlen(not_null_str) + 1));
	if (new_str == NULL)
		return (NULL);
	new_str[0] = '\0';
	sp_strcat(new_str, not_null_str);
	return (new_str);
}

static char	*sp_join_double_case(char *dest, char *src)
{
	char	*new_str;
	size_t	len;

	len = sp_strlen(dest) + sp_strlen(src);
	new_str = (char *)ft_calloc(sizeof(char), (len + 1));
	if (new_str == NULL)
		return (NULL);
	new_str[0] = '\0';
	sp_strcat(new_str, dest);
	sp_strcat(new_str, src);
	return (new_str);
}

char	*sp_join(char *dest, char *src)
{
	char	*new_string;

	if (dest == NULL || src == NULL)
		new_string = sp_join_single_case(dest, src);
	else
		new_string = sp_join_double_case(dest, src);
	if (dest != NULL)
		free(dest);
	return (new_string);
}
