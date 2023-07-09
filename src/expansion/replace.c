#include "../../include/minishell.h"

char	*calloc_new_str(char *str, char *target, char *new_word)
{
	size_t	new_str_size;
	
	new_str_size = strlen(str);
	new_str_size -= strlen(target);
	new_str_size += strlen(new_word);
	return (calloc(sizeof(char), (new_str_size + 1)));
}

void	fill_new_str(char *str, char *new_str, char *target, char *new_word)
{
	bool	single_quote_flag;
	bool	double_quote_flag;

	single_quote_flag = false;
	double_quote_flag = false;
	while (*str != '\0')
	{
		if (*str == '\'')
			reverse_flag(&single_quote_flag);
		if (*str == '"')
			reverse_flag(&double_quote_flag);
		if (*str == '$' && double_quote_flag == true)
			break ;
		if (*str == '$' && single_quote_flag == false)
			break ;
		*new_str++ = *str++;
	}
	str++;
	while (*str == *target && *target++ != '\0')
		str++;
	while (*new_word != '\0')
		*new_str++ = *new_word++;
	while (*str != '\0')
		*new_str++ = *str++;
}

char	*replace(char *str, char *target, char *new_word)
{
	char	*new_str_ptr;

	new_str_ptr = calloc_new_str(str, target, new_word);
	if (new_str_ptr == NULL)
		return (NULL);
	fill_new_str(str, new_str_ptr, target, new_word);
	free(str);
	return (new_str_ptr);
}
