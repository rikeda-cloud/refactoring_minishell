#include "../../include/minishell.h"

char	*type_to_char(int token_type)
{
	if (token_type == WORD)
		return ("WORD");
	else if (token_type == PIPE)
		return ("PIPE");
	else if (token_type == WRITE)
		return ("WRITE");
	else if (token_type == READ)
		return ("READ");
	else if (token_type == APPEND)
		return ("APPEND");
	else if (token_type == HEREDOC)
		return ("HEREDOC");
	else
		return ("Error");
}

size_t	printf_words(t_words *words)
{
	size_t	size;
	
	size = 0;
	while (words != NULL)
	{
		printf("%12s: %s\n", type_to_char(words->token_type), words->word);
		words = words->next;
		size++;
	}
	return (size);
}

void	print_tree_words(t_words *words)
{
	size_t	size;
	
	size = 0;
	while (words != NULL)
	{
		printf("[%s]", words->word);
		if (words->next != NULL)
			printf(" -> ");
		words = words->next;
		size++;
	}
	printf("\n");
}

void	print_tree(t_tree_node *node)
{
	if (node != NULL)
	{
		print_tree(node->left);
		printf("%12s : ", type_to_char(node->node_type));
		print_tree_words(node->word_list);
		print_tree(node->right);
	}
}

int	main (int argc, char **argv)
{
	t_words	*words;
	t_data	data;

	if (argc == 1)
	{
		printf("argc = 1\n");
		return (1);
	}
	printf("enter str -> %s\n", argv[1]);
	words = lexer(argv[1], &data);
	if (words != NULL)
	{
		printf_words(words);
		free_all_word_list(words);
	}
	return (0);
}


/* int	main (int argc, char **argv) */
/* { */
/* 	t_words		*words; */
/* 	t_tree_node	*root; */
/* 	t_data		data; */

/* 	if (argc == 1) */
/* 	{ */
/* 		printf("argc = 1\n"); */
/* 		return (1); */
/* 	} */
/* 	printf("enter str -> %s\n", argv[1]); */
/* 	words = lexer(argv[1], &data); */
/* 	if (words != NULL) */
/* 	{ */
/* 		root = create_tree(words); */
/* 		if (root != NULL) */
/* 		{ */
/* 			if (!check_syntax_err_tree(root)) */
/* 				print_tree(root); */
/* 			free_all_tree_node(root); */
/* 		} */
/* 	} */
/* 	return (0); */
/* } */
