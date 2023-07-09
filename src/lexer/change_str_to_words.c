#include "../../include/minishell.h"

static char	*search_next_word_top_ptr(char *str)
{
	size_t	size;

	size = count_word_size(str);
	return (&str[size]);
}

t_words *change_str_to_words(char *str)
{
	t_words	*words;
	t_words	*head;

	words = (t_words *)calloc(sizeof(t_words), 1);
	if (words == NULL)
		return (NULL);
	head = words;
	while (*str != '\0')
	{
		while (is_space(*str))
			str++;
		words->word = strdup_word(str);
		str = search_next_word_top_ptr(str);
		words -> next = (t_words *)calloc(sizeof(t_words), 1);
		words = words -> next;
	}
	return (head);
}
