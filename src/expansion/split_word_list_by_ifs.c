#include "../../include/minishell.h"

bool	is_ifs(int c)
{
	size_t	idx;

	idx = 0;
	while (IFS_CHAR[idx] != '\0')
	{
		if (IFS_CHAR[idx++] == c)
			return (true);
	}
	return (false);
}

bool	is_in_ifs_char(char *str)
{
	if (str == NULL)
		return (false);
	while (*str != '\0')
	{
		if (is_ifs(*str++))
			return (true);
	}
	return (false);
}

size_t	strlen_to_ifs(char *str)
{
	size_t	size;

	size = 0;
	while (str[size] != '\0' && is_ifs(str[size]) == false)
		size++;
	return (size);
}

t_words *split_word_by_ifs(t_words *words)
{
	t_words *third_word;
	t_words *second_word;
	t_words *ifs_word;
	char	*first_str;
	size_t	idx;

	idx = 0;
	second_word = ft_calloc(sizeof(t_words), 1);
	ifs_word = ft_calloc(sizeof(t_words), 1);
	ifs_word->token_type = TMP_IFS;
	third_word = words->next;
	first_str = strdup_n(words->word, strlen_to_ifs(words->word));
	while (is_ifs(words->word[idx]) == false && words->word[idx] != '\0')
		idx++;
	while (is_ifs(words->word[idx]) && words->word[idx] != '\0')
		idx++;
	second_word->word = ft_strdup(&words->word[idx]);
	free(words->word);
	words->word = first_str;
	words->next = ifs_word;
	words->next->next = second_word;
	second_word->next = third_word;
	return (words);
}

void	split_word_list_by_ifs(t_words *words)
{
	int	quote_mode;

	quote_mode = NOT_Q_MODE;
	while (words != NULL && words->word != NULL)
	{
		if (is_token_type_quotation(words->token_type))
			change_quote_mode(&quote_mode, words->token_type);
		else if (quote_mode == NOT_Q_MODE && is_in_ifs_char(words->word))
			words = split_word_by_ifs(words);
		words = words->next;
	}
}
