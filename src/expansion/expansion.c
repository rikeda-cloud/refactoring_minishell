#include "../../include/minishell.h"

t_words	*append_word_list(t_words *dst, t_words *src, bool *err_flag)
{
	t_words	*dst_head_ptr;

	if (*err_flag)
		return (dst);
	if (dst == NULL)
		return (src);
	dst_head_ptr = dst;
	while (dst->next != NULL)
		dst = dst->next;
	dst->next = src;
	return (dst_head_ptr);
}

t_words *expansion_node_heredoc_pattern(t_tree_node *node, bool *err_flag)
{
	t_words *heredoc;
	t_words *delimiter;

	heredoc = new_redirect_node(node->word_list->token_type);
	if (heredoc == NULL)
		return (reverse_flag(err_flag));
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

t_words *expansion_node(t_tree_node *node, bool *err_flag)
{
	t_words *word_list;

	if (is_redirect(node->word_list->token_type))
	{
		word_list = new_redirect_node(node->word_list->token_type);
		if (word_list == NULL)
			*err_flag = true;
	}
	else
	{
		word_list = split_str_by_quote(node->word_list->word);
		variable_expansion(word_list, err_flag);
		if (*err_flag)
			return (free_all_word_list(word_list));
		split_word_list_by_ifs(word_list, err_flag);
		if (*err_flag)
			return (free_all_word_list(word_list));
		word_list = trim_quote_and_cat(word_list, err_flag);
		if (*err_flag)
			return (NULL);
	}
	return (word_list);
}

t_words	*expansion(t_tree_node *node, bool *err_flag)
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
			word_list = expansion_node_heredoc_pattern(node, err_flag);
			node->word_list = node->word_list->next;
		}
		else
			word_list = expansion_node(node, err_flag);
		new_word_list = append_word_list(new_word_list, word_list, err_flag);
		node->word_list = node->word_list->next;
	}
	if (*err_flag)
		new_word_list = free_all_word_list(new_word_list);
	free_all_word_list(word_list_head);
	return (new_word_list);
}

void	expansion_tree(t_tree_node *node, bool *err_flag)
{
	node = get_leftmost_node(node);
	node->word_list = expansion(node, err_flag);
	if (node->prev == NULL || *err_flag)
		return ;
	else if (node->prev->prev == NULL)
		node->prev->right->word_list = expansion(node->prev->right, err_flag);
	else
	{
		node = node->prev->right;
		while (node->prev->prev && node->prev->prev->right)
		{
			node->word_list = expansion(node, err_flag);
			node = node->prev->prev->right;
			if (*err_flag)
				return ;
		}
		node->word_list = expansion(node, err_flag);
	}
}
