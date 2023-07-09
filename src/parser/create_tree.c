#include "../../include/minishell.h"

static t_words	*get_target_word(t_words *words, t_token_type type)
{
	t_words	*tmp_word_ptr;

	while (words->token_type != END)
	{
		if (words->token_type == type)
			tmp_word_ptr = words;
		words = words->next;
	}
	return (tmp_word_ptr);
}

static t_words	*get_target_prev_word(t_words *words, t_token_type type)
{
	t_words	*tmp_word_ptr;
	t_words	*tmp_prev_word_ptr;

	tmp_prev_word_ptr = words;
	while (words->token_type != END)
	{
		if (words->token_type == type)
			tmp_word_ptr = tmp_prev_word_ptr;
		tmp_prev_word_ptr = words;
		words = words->next;
	}
	return (tmp_word_ptr);
}

static void	split_by_type(t_tree_node *node, t_token_type type)
{
	t_tree_node	*left;
	t_tree_node	*right;
	t_words		*tmp_word_ptr;

	left = (t_tree_node *)calloc(sizeof(t_tree_node), 1);
	right = (t_tree_node *)calloc(sizeof(t_tree_node), 1);
	tmp_word_ptr = get_target_word(node->word_list, type);
	left->word_list = node->word_list;
	node->word_list = tmp_word_ptr;
	right->word_list = tmp_word_ptr->next;
	node->word_list->next = (t_words *)calloc(sizeof(t_words), 1);
	tmp_word_ptr = get_target_prev_word(left->word_list, type);
	tmp_word_ptr->next = (t_words *)calloc(sizeof(t_words), 1);
	node->left = left;
	node->right = right;
	left->prev = node;
	right->prev = node;
}

void	recursive_split_by_pipe(t_tree_node *node)
{
	/* if (node != NULL && check_in_type(node->word_list, SEMICOLON)) */
	/* { */
	/* 	split_by_type(node, SEMICOLON); */
	/* 	recursive_split_by_semicolon_pipe(node->left); */
	/* 	recursive_split_by_semicolon_pipe(node->right); */
	/* } */
	if (node != NULL && check_in_type(node->word_list, PIPE))
	{
		split_by_type(node, PIPE);
		recursive_split_by_pipe(node->left);
		recursive_split_by_pipe(node->right);
	}
	if (node != NULL)
		add_node_type(node);
}

t_tree_node	*create_tree(t_words *words)
{
	t_tree_node	*root;

	root = (t_tree_node *)calloc(sizeof(t_tree_node), 1);
	if (root == NULL)
	{
		printf("ERRR\n");
		exit(1);
	}
	root->word_list = words;
	recursive_split_by_pipe(root);
	return (root);
}
