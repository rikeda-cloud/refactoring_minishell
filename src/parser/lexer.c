#include "../../include/minishell.h"

t_words	*lexer(const char *str, t_data *data)
{
	t_words	*word_list;

	word_list = change_str_to_word_list(str);
	if (word_list == NULL)
		return (NULL);
	add_words_type(word_list);
	if (check_not_close_quotation(word_list))
	{
		word_list = free_all_word_list(word_list);
		data->err_number = 1;
	}
	else if (check_syntax_err_words(word_list))
	{
		word_list = free_all_word_list(word_list);
		data->err_number = 1;
	}
	return (word_list);
}
