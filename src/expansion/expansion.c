#include "../../include/minishell.h"

static t_words	*do_all_expansion(char *str, bool *err_flag)
{
	t_words	*word_list;

	word_list = split_str_by_quote(str);
	variable_expansion(word_list, err_flag);
	if (*err_flag)
		return (free_all_word_list(word_list));
	split_word_list_by_ifs(word_list, err_flag);
	if (*err_flag)
		return (free_all_word_list(word_list));
	word_list = trim_quote_and_cat(word_list, err_flag);
	if (*err_flag)
		return (NULL);
	return (word_list);
}

static t_words	*do_not_word_split_expansion(char *str, bool *err_flag)
{
	t_words	*word_list;

	word_list = split_str_by_quote(str);
	variable_expansion(word_list, err_flag);
	if (*err_flag)
		return (free_all_word_list(word_list));
	word_list = trim_quote_and_cat(word_list, err_flag);
	if (*err_flag)
		return (NULL);
	return (word_list);
}

static t_words	*expansion_node(t_tree_node *node, bool *err_flag, bool flag)
{
	t_words *word_list;

	if (is_redirect(node->word_list->token_type))
	{
		word_list = new_redirect_node(node->word_list->token_type);
		if (word_list == NULL)
			*err_flag = true;
		return (word_list);
	}
	else if (flag && is_in_equal(node->word_list->word))
		return (do_not_word_split_expansion(node->word_list->word, err_flag));
	else
		return (do_all_expansion(node->word_list->word, err_flag));
}

t_words	*expansion_normal_pattern(t_tree_node *node, bool *err_flag)
{
	t_words	*word_list_head;
	t_words	*word_list;
	t_words	*new_word_list;

	word_list_head = node->word_list;
	new_word_list = NULL;
	while (!(*err_flag) && node->word_list != NULL)
	{
		if (node->word_list->token_type == HEREDOC)
		{
			word_list = expansion_heredoc_node(node, err_flag);
			node->word_list = node->word_list->next;
		}
		else
			word_list = expansion_node(node, err_flag, false);
		new_word_list = append_word_list(new_word_list, word_list, err_flag);
		node->word_list = node->word_list->next;
	}
	if (*err_flag)
		new_word_list = free_all_word_list(new_word_list);
	free_all_word_list(word_list_head);
	return (new_word_list);
}

t_words	*expansion_assignment_pattern(t_tree_node *node, bool *err_flag)
{
	t_words	*word_list_head;
	t_words	*word_list;
	t_words	*new_word_list;

	word_list_head = node->word_list;
	new_word_list = NULL;
	while (!(*err_flag) && node->word_list != NULL)
	{
		if (node->word_list->token_type == HEREDOC)
		{
			word_list = expansion_heredoc_node(node, err_flag);
			node->word_list = node->word_list->next;
		}
		else
			word_list = expansion_node(node, err_flag, true);
		new_word_list = append_word_list(new_word_list, word_list, err_flag);
		node->word_list = node->word_list->next;
	}
	if (*err_flag)
		new_word_list = free_all_word_list(new_word_list);
	free_all_word_list(word_list_head);
	return (new_word_list);
}
