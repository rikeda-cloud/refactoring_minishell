#include "../../include/minishell.h"

static t_words	*append_word_list(t_words *dst, t_words *src, bool *err_flag)
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

t_words	*do_expansion(t_tree_node *node, bool *err_flag, bool assign_flag, t_data *data)
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
			if (node->word_list->next != NULL)
				node->word_list = node->word_list->next;
		}
		else
			word_list = expansion_node(node, err_flag, assign_flag, data);
		new_word_list = append_word_list(new_word_list, word_list, err_flag);
		node->word_list = node->word_list->next;
	}
	if (*err_flag)
		new_word_list = free_all_word_list(new_word_list);
	free_all_word_list(word_list_head);
	return (new_word_list);
}

static t_words	*expansion(t_tree_node *node, bool *err_flag, t_data *data)
{
	if (is_assignment_pattern(node))
		return (do_expansion(node, err_flag, true, data));
	else
		return (do_expansion(node, err_flag, false, data));
}

void	expansion_tree(t_tree_node *node, bool *err_flag, t_data *data)
{
	node = get_leftmost_node(node);
	node->word_list = expansion(node, err_flag, data);
	if (node->prev == NULL || *err_flag)
		return ;
	else if (node->prev->prev == NULL)
		node->prev->right->word_list = expansion(node->prev->right, err_flag, data);
	else
	{
		node = node->prev->right;
		while (node->prev->prev && node->prev->prev->right)
		{
			node->word_list = expansion(node, err_flag, data);
			node = node->prev->prev->right;
			if (*err_flag)
				return ;
		}
		node->word_list = expansion(node, err_flag, data);
	}
}
