#include "include/minishell.h"

void	*free_word_node(t_words *word_node)
{
	if (word_node != NULL && word_node->word != NULL)
		free_str(word_node->word);
	if (word_node != NULL)
		free(word_node);
	return (NULL);
}

t_words	*free_word_node_get_next_node(t_words *word_node)
{
	t_words	*next_node;

	next_node = word_node->next;
	free_word_node(word_node);
	return (next_node);
}

t_words	*append_word_node(t_words *list, t_words *word_node)
{
	t_words	*list_head;

	if (list == NULL)
		return (word_node);
	list_head = list;
	while (list->next != NULL)
		list = list->next;
	list->next = word_node;
	return (list_head);
}

t_words	*delete_redirect_node(t_words *word_list)
{
	t_words	*new_word_list;
	t_words	*tmp;

	new_word_list = NULL;
	while (word_list != NULL)
	{
		if (is_redirect(word_list->token_type))
		{
			word_list = free_word_node_get_next_node(word_list);
			word_list = free_word_node_get_next_node(word_list);
		}
		else
		{
			tmp = word_list;
			word_list = word_list->next;
			tmp->next = NULL;
			new_word_list = append_word_node(new_word_list, tmp);
		}
	}
	return (new_word_list);
}
