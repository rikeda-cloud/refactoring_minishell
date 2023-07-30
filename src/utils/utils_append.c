#include "../../include/minishell.h"

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

t_words	*append_with_flag(t_words *list, t_words *word_node, bool err_flag)
{
	if (err_flag)
		return (list);
	return (append_word_node(list, word_node));
}

t_words	*append_str_to_word_list(t_words *word_list, const char *str)
{
	t_words	*word_list_top_ptr;

	word_list_top_ptr = word_list;
	if (word_list == NULL)
		word_list_top_ptr = new_word_node(str);
	else
	{
		while (word_list->next != NULL)
			word_list = word_list->next;
		word_list->next = new_word_node(str);
		if (word_list->next == NULL)
		{
			free_all_word_list(word_list_top_ptr);
			word_list_top_ptr = NULL;
		}
	}
	return (word_list_top_ptr);
}
