#include "../../include/minishell.h"

static char	*search_next_word_top_ptr(char *str)
{
	size_t	size;

	size = count_word_size(str);
	return (&str[size]);
}

static char	*search_next_not_space_char_ptr(char *str)
{
	while (*str != '\0' && is_space(*str))
		str++;
	return (str);
}

t_words *change_str_to_words(char *str)
{
	t_words	*words;
	t_words	*head;

	head = NULL;
	while (*str != '\0')
	{
		str = search_next_not_space_char_ptr(str);
		if (*str == '\0')
			break;
		if (head == NULL)
		{
			words = (t_words *)calloc(sizeof(t_words), 1);
			head = words;
		}
		else
		{
			words -> next = (t_words *)calloc(sizeof(t_words), 1);
			words = words->next;
		}
		words->word = strdup_word(str);
		str = search_next_word_top_ptr(str);
	}
	return (head);
}
