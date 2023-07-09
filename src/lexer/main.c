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

int	main (int argc, char **argv)
{
	t_words	*words;

	if (argc == 1)
	{
		printf("argc = 1\n");
		return (1);
	}
	printf("enter str -> %s\n", argv[1]);
	words = lexical_analysis(argv[1]);
	if (check_not_close_quotation(words))
	{
		printf("Error not close quote\n");
		return (1);
	}
	if (words != NULL)
		printf_words(words);
	return (0);
}

