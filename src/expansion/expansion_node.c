#include "../../include/minishell.h"

t_words	*do_all_expansion(char *str, t_data *data)
{
	t_words	*word_list;

	word_list = split_str_by_quote(str);
	variable_expansion(word_list, data);
	if (data->err_flag)
		return (free_all_word_list(word_list));
	split_word_list_by_ifs(word_list, data);
	if (data->err_flag)
		return (free_all_word_list(word_list));
	word_list = trim_quote_and_cat(word_list, &data->err_flag);
	if (data->err_flag)
		return (NULL);
	return (word_list);
}

t_words	*do_expansion_not_word_split(char *str, t_data *data)
{
	t_words	*word_list;

	word_list = split_str_by_quote(str);
	variable_expansion(word_list, data);
	if (data->err_flag)
		return (free_all_word_list(word_list));
	word_list = trim_quote_and_cat(word_list, &data->err_flag);
	if (data->err_flag)
		return (NULL);
	return (word_list);
}

t_words	*expansion_node(t_tree_node *node, bool assign_flag, t_data *data)
{
	t_words *word_list;

	if (is_redirect(node->word_list->token_type))
	{
		word_list = new_redirect_node(node->word_list->token_type);
		if (word_list == NULL)
		{
			data->err_flag = true;
			return (NULL);
		}
		return (word_list);
	}
	else if (is_do_not_word_split_pattern(assign_flag, node->word_list->word))
		return (do_expansion_not_word_split(node->word_list->word, data));
	else
		return (do_all_expansion(node->word_list->word, data));
}

t_words *expansion_heredoc_node(t_tree_node *node, bool *err_flag)
{
	t_words *heredoc;
	t_words *delimiter;

	heredoc = new_redirect_node(node->word_list->token_type);
	if (heredoc == NULL)
		return (reverse_flag(err_flag));
	if (node->word_list->next == NULL)
		return (heredoc);
	delimiter = split_str_by_quote(node->word_list->next->word);
	if (delimiter == NULL)
	{
		reverse_flag(err_flag);
		return (free_word_node(heredoc));
	}
	delimiter = trim_quote_and_cat(delimiter, err_flag);
	if (*err_flag)
		return (free_word_node(heredoc));
	delimiter->token_type = get_delimiter_type(node->word_list->next->word);
	heredoc->next = delimiter;
	return (heredoc);
}
