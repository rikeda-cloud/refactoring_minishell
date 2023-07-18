#include "../../include/minishell.h"

void	free_word_node(t_words *word_node)
{
	if (word_node != NULL && word_node->word != NULL)
		free(word_node->word);
	if (word_node != NULL)
		free(word_node);
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

static void	recursive_free_tree_node(t_tree_node *node)
{
	t_tree_node	*left;
	t_tree_node	*right;

	if (node != NULL)
	{
		left = node->left;
		right = node->right;
		free_all_word_list(node->word_list);
		free(node);
		recursive_free_tree_node(left);
		recursive_free_tree_node(right);
	}
}

void	*free_all_tree_node(t_tree_node *root)
{
	recursive_free_tree_node(root);
	return (NULL);
}
