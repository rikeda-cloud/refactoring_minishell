#include "../../include/minishell.h"

t_words	*lexer(const char *str, t_data *data)
{
	t_words	*word_list;

	word_list = change_str_to_word_list(str, data);
	if (word_list == NULL)
		return (NULL);
	add_words_type(word_list);
	if (check_not_close_quotation(word_list))
		word_list = free_all_word_list(word_list);
	else if (check_syntax_err_words(word_list, data))
		word_list = free_all_word_list(word_list);
	return (word_list);
}
