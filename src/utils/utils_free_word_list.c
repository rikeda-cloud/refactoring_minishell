#include "../../include/minishell.h"

void	*free_str(char *str)
{
	if (str != NULL)
		free(str);
	return (NULL);
}

void	*free_word_node(t_words *word_node)
{
	if (word_node != NULL && word_node->word != NULL)
		free_str(word_node->word);
	if (word_node != NULL)
		free(word_node);
	return (NULL);
}

void	*free_all_word_list(t_words *word_list)
{
	t_words	*tmp;

	while (word_list != NULL)
	{
		tmp = word_list;
		word_list = word_list->next;
		free_word_node(tmp);
	}
	return (NULL);
}
