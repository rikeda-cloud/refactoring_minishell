#include "../../include/minishell.h"

static void	set_q_char(int *q_char, int	c)
{
	if (*q_char == '\0')
		*q_char = c;
	else
		*q_char = '\0';
}

t_token_type type_single_or_double(int c)
{
	if (c == '\'')
		return (TMP_SINGLE_QUOTE);
	else
		return (TMP_DOUBLE_QUOTE);
}

t_words *append_word(t_words *words, char *str, size_t size, int flag)
{
	t_words *words_top_ptr;

	if (words == NULL)
	{
		words_top_ptr = ft_calloc(sizeof(t_words), 1);
		words_top_ptr->word = strdup_n(str, size);
		if (flag)
			words_top_ptr->token_type = type_single_or_double(*str);
	}
	else
	{
		words_top_ptr = words;
		while (words->next != NULL)
			words = words->next;
		words->next = ft_calloc(sizeof(t_words), 1);
		words->next->word = strdup_n(str, size);
		if (flag)
			words->next->token_type = type_single_or_double(*str);
	}
	return (words_top_ptr);
}

t_words	*split_str_by_quote(char *str)
{
	char	*save_ptr;
	int		q_char;
	t_words *new_word;

	q_char = '\0';
	save_ptr = str;
	new_word = NULL;
	while (*str != '\0')
	{
		if (is_quotation(*str) && (q_char == '\0' || q_char == *str))
		{
			set_q_char(&q_char, *str);
			if (str - save_ptr != 0)
				new_word = append_word(new_word, save_ptr, str - save_ptr, 0);
			new_word = append_word(new_word, str, 1, 1);
			save_ptr = str;
			save_ptr++;
		}
		str++;
	}
	if (str - save_ptr != 0)
		new_word = append_word(new_word, save_ptr, str- save_ptr, 0);
	return (new_word);
}
