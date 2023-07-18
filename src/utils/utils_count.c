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
			quote_flag = false;
		else if (is_quotation(str[size]) && quote_flag == false)
		{
			quote_char = str[size];
			quote_flag = true;
		}
		else if (quote_flag == false && is_special_char(str[size]) && size != 0)
			return (size);
		else if (quote_flag == false && is_special_char(str[size]) && size == 0)
			return (check_append_or_heredoc_pattern(&str[size]));
		size++;
	}
	return (size);
}

size_t	count_new_word_size(char *word)
{
	int		quote_char;
	size_t	counter;

	counter = 0;
	if (*word != '\0' && is_quotation(*word) == false)
		return (0);
	quote_char = *word;
	while (*word != '\0')
	{
		counter++;
		word++;
	}
	word--;
	if (*word == quote_char && counter >= 3)
		return (counter - 2);
	else
		return (0);
}

size_t	count_to_front_of_c(char *str, int c)
{
	size_t	size;

	size = 0;
	while (str[size] != c && str[size] != '\0')
		size++;
	return (size);
}

