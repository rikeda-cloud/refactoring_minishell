#include "../../include/minishell.h"

static const char	*skip_space_char(const char *str)
{
	while (is_space(*str))
		str++;
	return (str);
}

static t_words	*append_str_to_word_list(t_words *word_list, const char *str)
{
	t_words	*word_list_top_ptr;

	word_list_top_ptr = word_list;
	if (word_list == NULL)
		word_list_top_ptr = new_word_node(str);
	else
	{
		while (word_list->next != NULL)
			word_list = word_list->next;
		word_list->next = new_word_node(str);
		if (word_list->next == NULL)
		{
			free_all_word_list(word_list_top_ptr);
			word_list_top_ptr = NULL;
		}
	}
	return (word_list_top_ptr);
}

t_words *change_str_to_word_list(const char *str, t_data *data)
{
	t_words	*word_list;

	word_list = NULL;
	while (*str != '\0')
	{
		str = skip_space_char(str);
		if (*str == '\0')
			break;
		word_list = append_str_to_word_list(word_list, str);
		if (word_list == NULL)
			return (reverse_flag(&data->err_flag));
		str = &str[count_word_size(str)];
	}
	return (word_list);
}
