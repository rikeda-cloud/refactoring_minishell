#include "../../include/minishell.h"

void	reverse_flag(bool	*flag)
{
	if (*flag == true)
		*flag = false;
	else if (*flag == false)
		*flag = true;
}

bool	is_dallor_in_str(char *str)
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
			return (true);
		if (*str == '$' && single_quote_flag == false)
			return (true);
		str++;
	}
	return (false);
}

size_t	count_env_size(char *str)
{
	size_t	counter;

	counter = 0;
	if (*str == '?')
		return (1);
	else
	{
		while (str[counter] != '\0' && ft_isalnum(str[counter]))
			counter++;
	}
	return (counter);
}

char	*strdup_env(char *str)
{
	bool	single_quote_flag;
	bool	double_quote_flag;

	if (is_dallor_in_str(str) == false)
		return (NULL);
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
		str++;
	}
	str++;
	return (strdup_n(str, count_env_size(str)));
}
