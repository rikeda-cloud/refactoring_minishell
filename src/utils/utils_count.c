#include "../../include/minishell.h"

static size_t	check_append_or_heredoc_pattern(const char *str)
{
	if (str[0] == '>' && str[1] == '>')
		return (2);
	else if (str[0] == '<' && str[1] == '<')
		return (2);
	else
		return (1);
}

size_t	count_word_size(const char *str)
{
	size_t	size;
	bool	quote_flag;
	int		quote_char;

	size = 0;
	quote_flag = false;
	while (str[size] != '\0')
	{
		if (is_quotation(str[size]) && quote_flag && str[size] == quote_char)
			reverse_flag(&quote_flag);
		else if (is_quotation(str[size]) && !quote_flag)
		{
			quote_char = str[size];
			reverse_flag(&quote_flag);
		}
		else if (!quote_flag && is_special_char(str[size]) && size != 0)
			return (size);
		else if (!quote_flag && is_special_char(str[size]) && size == 0)
			return (check_append_or_heredoc_pattern(&str[size]));
		size++;
	}
	return (size);
}

size_t	count_to_front_of_c(char *str, int c)
{
	size_t	size;

	size = 0;
	while (str[size] != c && str[size] != '\0')
		size++;
	return (size);
}

size_t	count_env_size(const char *str)
{
	size_t	counter;

	counter = 0;
	str++;
	if (*str == '?')
		return (1);
	while (str[counter] != '\0')
	{
		if (ft_isalnum(str[counter]) || *str == '_')
			counter++;
		else
			break;
	}
	return (counter);
}

static size_t	count_hash_list_size(t_env *hash_list)
{
	size_t	size;

	size = 0;
	while (hash_list != NULL)
	{
		size++;
		hash_list = hash_list->next;
	}
	return (size);
}

size_t	count_map_size(t_env **map)
{
	size_t	idx;
	size_t	size;

	idx = 0;
	size = 0;
	while (idx < HASH_MAP_SIZE)
		size += count_hash_list_size(map[idx++]);
	return (size);
}
