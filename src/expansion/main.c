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
	else if (token_type == COMMAND)
		return ("COMMAND");
	else if (token_type == DELIMITER)
		return ("DELIMITER");
	else if (token_type == DELIMITER_QUOTE)
		return ("DELIMITER_QUOTE");
	else
		return ("Error");
}

size_t	print_words(t_words *words)
{
	size_t	size;
	
	size = 0;
	while (words != NULL && words->word != NULL)
	{
		printf("[[%s]:%s]", type_to_char(words->token_type), words->word);
		if (words->next != NULL && words->next->word != NULL)
			printf(" -> ");
		words = words->next;
		size++;
	}
	printf("\n");
	return (size);
}

void	print_tree(t_tree_node *node)
{
	if (node != NULL && node->word_list != NULL)
	{
		print_tree(node->left);
		printf("%12s : ", type_to_char(node->node_type));
		print_words(node->word_list);
		print_tree(node->right);
	}
}

int	main (int argc, char **argv)
{
	t_data	data;

	data.env_map = change_environ_to_hash_map();
	t_words *words;
	t_tree_node *root;
	bool	faild_flag;

	if (argc == 1)
	{
		printf("argc = 1\n");
		return (1);
	}
	words = lexer(argv[1], &data);
	if (check_syntax_err_words(words))
		return (0);
	root = create_tree(words);
	if (root != NULL)
		print_tree(root);
	faild_flag = false;
	expansion_tree(root, &faild_flag, &data);
	if (faild_flag == false)
		print_tree(root);
	if (check_syntax_err_tree(root))
		return (0);
	return (0);
}
