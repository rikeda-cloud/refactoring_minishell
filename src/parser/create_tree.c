#include "../../include/minishell.h"

static t_words	*get_target_word(t_words *word_list, t_token_type type)
{
	t_words	*tmp_word_ptr;

	tmp_word_ptr = NULL;
	while (word_list != NULL)
	{
		if (word_list->token_type == type)
			tmp_word_ptr = word_list;
		word_list = word_list->next;
	}
	return (tmp_word_ptr);
}

static t_words	*get_target_prev_word(t_words *word_list, t_token_type type)
{
	t_words	*tmp_word_ptr;
	t_words	*tmp_prev_word_ptr;

	tmp_word_ptr = NULL;
	tmp_prev_word_ptr = word_list;
	while (word_list != NULL)
	{
		if (word_list->token_type == type)
			tmp_word_ptr = tmp_prev_word_ptr;
		tmp_prev_word_ptr = word_list;
		word_list = word_list->next;
	}
	return (tmp_word_ptr);
}

static void	split_by_pipe(t_tree_node *node, t_token_type type, bool *err_flag)
{
	t_words	*tmp_word_ptr;

	node->left = (t_tree_node *)ft_calloc(sizeof(t_tree_node), 1);
	if (node->left == NULL)
	{
		*err_flag = true;
		return ;
	}
	node->right = (t_tree_node *)ft_calloc(sizeof(t_tree_node), 1);
	if (node->right == NULL)
	{
		free(node->left);
		*err_flag = true;
		return ;
	}
	node->left->word_list = node->word_list;
	node->word_list = get_target_word(node->word_list, type);
	node->right->word_list = node->word_list->next;
	node->word_list->next = NULL;
	tmp_word_ptr = get_target_prev_word(node->left->word_list, type);
	tmp_word_ptr->next = NULL;
	node->left->prev = node;
	node->right->prev = node;
}

static void	recursive_split_by_pipe(t_tree_node *node, bool *err_flag)
{
	if (*err_flag)
		return ;
	if (node != NULL && is_type_in_word_list(node->word_list, PIPE_CHAR))
	{
		split_by_pipe(node, PIPE_CHAR, err_flag);
		recursive_split_by_pipe(node->left, err_flag);
		recursive_split_by_pipe(node->right, err_flag);
	}
	if (node != NULL)
		add_node_type(node);
}

t_tree_node	*create_tree(t_words *word_list, t_data *data)
{
	t_tree_node	*root;

	root = (t_tree_node *)ft_calloc(sizeof(t_tree_node), 1);
	if (root == NULL)
	{
		free_all_word_list(word_list);
		return (reverse_flag(&data->err_flag));
	}
	root->word_list = word_list;
	recursive_split_by_pipe(root, &data->err_flag);
	if (data->err_flag)
		root = free_all_tree_node(root);
	return (root);
}
