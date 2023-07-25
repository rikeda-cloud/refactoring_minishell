#include "../../include/minishell.h"

static t_words	*append_word_node_to_list(t_words *list, t_words *word_node)
{
	t_words	*list_head;

	list_head = list;
	if (list == NULL)
		return (word_node);
	while (list->next != NULL)
		list = list->next;
	list->next = word_node;
	return (list_head);
}

static t_words	*delete_null_word_node(t_words *word_list)
{
	t_words	*new_word_list;
	t_words	*tmp;

	new_word_list = NULL;
	while (word_list != NULL)
	{
		if (word_list->word == NULL)
		{
			tmp = word_list;
			word_list = word_list->next;
			free_word_node(tmp);
		}
		else
		{
			tmp = word_list;
			word_list = word_list->next;
			tmp->next = NULL;
			new_word_list = append_word_node_to_list(new_word_list, tmp);
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
