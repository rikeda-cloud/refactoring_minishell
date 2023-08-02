#include "../../include/minishell.h"

static t_words	*sever_connect_and_skip_n(t_words *word_list, size_t n)
{
	t_words	*head;
	size_t	idx;

	idx = 0;
	while (idx < n)
	{
		head = word_list;
		word_list = word_list->next;
		idx++;
	}
	head->next = NULL;
	return (word_list);
}

static t_words	*delete_null_word_node(t_words *word_list)
{
	t_words	*new_word_list;
	t_words	*tmp;

	new_word_list = NULL;
	while (word_list != NULL)
	{
		if (is_redirect(word_list->token_type))
		{
			tmp = word_list;
			word_list = sever_connect_and_skip_n(word_list, 2);
			new_word_list = append_word_node(new_word_list, tmp);
		}
		else if (word_list->word == NULL)
			word_list = free_word_node_get_next_node(word_list);
		else
		{
			tmp = word_list;
			word_list = sever_connect_and_skip_n(word_list, 1);
			new_word_list = append_word_node(new_word_list, tmp);
		}
	}
	return (new_word_list);
}

void	del_null_word_node_in_tree(t_tree_node *node)
{
	node = get_leftmost_node(node);
	node->word_list = delete_null_word_node(node->word_list);
	if (node->prev == NULL)
		return ;
	node = node->prev->right;
	while (node->prev->prev != NULL)
	{
		node->word_list = delete_null_word_node(node->word_list);
		node = node->prev->prev->right;
	}
	node->word_list = delete_null_word_node(node->word_list);
}
