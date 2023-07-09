#include "../../include/minishell.h"

t_tree_node		*get_start_node(t_tree_node *node)
{
	while (node->left != NULL)
		node = node->left;
	return (node);
}

t_words *expansion_node(t_tree_node *node)
{
	t_words *word_list;

	if (is_redirect(node->word_list->token_type))
	{
		word_list = ft_calloc(sizeof(t_words), 1);
		word_list->word = ft_strdup(node->word_list->word);
		word_list->token_type = node->word_list->token_type;
		if (node->word_list->token_type == HEREDOC)
		{
			word_list->next = ft_calloc(sizeof(t_words), 1);
			word_list->next->word = ft_strdup(node->word_list->next->word);
			word_list->next->token_type = node->word_list->next->token_type;
		}
	}
	else
	{
		word_list = split_str_by_quote(node->word_list->word);
		variable_expansion(word_list);
		split_word_list_by_ifs(word_list);
		word_list = trim_quote_and_cat(word_list);
	}
	return (word_list);
}

t_words	*expansion(t_tree_node *node)
{
	t_words	*word_list;
	t_words	*new_word_list;
	t_words	*new_word_list_top_ptr;

	new_word_list_top_ptr = NULL;
	while (node->word_list != NULL && node->word_list->word != NULL)
	{
		word_list = expansion_node(node);
		if (new_word_list_top_ptr == NULL)
		{
			new_word_list = word_list;
			new_word_list_top_ptr = new_word_list;
		}
		else
		{
			while (new_word_list->next != NULL)
				new_word_list = new_word_list->next;
			new_word_list->next = word_list;
		}
		if (node->word_list->token_type == HEREDOC)
			node->word_list = node->word_list->next;
		node->word_list = node->word_list->next;
	}
	return (new_word_list_top_ptr);
}

void	expansion_tree(t_tree_node *node)
{
	node = get_start_node(node);
	if (node->prev == NULL)
		node->word_list = expansion(node);
	else if (node->prev->prev == NULL)
	{
		node->word_list = expansion(node);
		node->prev->left->word_list = expansion(node->prev->left);
	}
	else
	{
		node->word_list = expansion(node);
		node = node->prev->right;
		while (node->prev->prev != NULL && node->prev->prev->right != NULL)
		{
			node->word_list = expansion(node);
			node = node->prev->prev->right;
		}
		node->word_list = expansion(node);
	}
}
