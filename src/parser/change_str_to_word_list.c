#include "../../include/minishell.h"

static const char	*search_word_next_ptr(const char *str)
{
	size_t	size;

	size = count_word_size(str);
	return (&str[size]);
}

static const char	*skip_space_char(const char *str)
{
	while (is_space(*str))
		str++;
	return (str);
}

static t_words	*new_word(const char *str)
{
	t_words	*word_list;

	word_list = (t_words *)ft_calloc(sizeof(t_words), 1);
	if (word_list == NULL)
		return (NULL);
	word_list->word = strdup_word(str);
	if (word_list->word == NULL)
	{
		free(word_list);
		return (NULL);
	}
	return (word_list);
}

static t_words	*append_word_to_word_list(t_words *word_list, const char *str)
{
	t_words	*word_list_top_ptr;

	word_list_top_ptr = word_list;
	if (word_list == NULL)
		word_list_top_ptr = new_word(str);
	else
	{
		while (word_list->next != NULL)
			word_list = word_list->next;
		word_list->next = new_word(str);
		if (word_list->next == NULL)
		{
			free_all_word_list(word_list_top_ptr);
			word_list_top_ptr = NULL;
		}
	}
	return (word_list_top_ptr);
}

t_words *change_str_to_word_list(const char *str)
{
	t_words	*word_list;

	word_list = NULL;
	while (*str != '\0')
	{
		str = skip_space_char(str);
		if (*str == '\0')
			break;
		word_list = append_word_to_word_list(word_list, str);
		if (word_list == NULL)
			return (NULL);
		str = search_word_next_ptr(str);
	}
	return (word_list);
}
