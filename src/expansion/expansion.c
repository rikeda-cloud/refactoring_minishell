#include "../../include/minishell.h"

t_words	*do_expansion(t_tree_node *node, bool assign_flag, t_data *data)
{
	t_words	*word_list_head;
	t_words	*word_list;
	t_words	*new_list;

	word_list_head = node->word_list;
	new_list = NULL;
	while (data->err_flag == false && node->word_list != NULL)
	{
		if (node->word_list->token_type == HEREDOC)
		{
			word_list = expansion_heredoc_node(node, &data->err_flag);
			if (node->word_list->next != NULL)
				node->word_list = node->word_list->next;
		}
		else
			word_list = expansion_node(node, assign_flag, data);
		new_list = append_with_flag(new_list, word_list, data->err_flag);
		node->word_list = node->word_list->next;
	}
	if (data->err_flag)
		new_list = free_all_word_list(new_list);
	free_all_word_list(word_list_head);
	return (new_list);
}

static t_words	*expansion(t_tree_node *node, t_data *data)
{
	if (is_assignment_pattern(node))
		return (do_expansion(node, true, data));
	else
		return (do_expansion(node, false, data));
}

void	expansion_tree(t_tree_node *node, t_data *data)
{
	node = get_leftmost_node(node);
	node->word_list = expansion(node, data);
	if (node->prev == NULL || data->err_flag)
		return ;
	else if (node->prev->prev == NULL)
		node->prev->right->word_list = expansion(node->prev->right, data);
	else
	{
		node = node->prev->right;
		while (node->prev->prev && node->prev->prev->right)
		{
			node->word_list = expansion(node, data);
			node = node->prev->prev->right;
			if (data->err_flag)
				return ;
		}
		node->word_list = expansion(node, data);
	}
}
