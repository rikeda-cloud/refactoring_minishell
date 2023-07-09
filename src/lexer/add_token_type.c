#include "../../include/minishell.h"

static void	identify_word_type(t_words *words)
{
	if (ft_strncmp(words->word, "|", 2) == 0)
		words->token_type = PIPE_CHAR;
	else if (ft_strncmp(words->word, "<<", 3) == 0)
		words->token_type = HEREDOC;
	else if (ft_strncmp(words->word, ">>", 3) == 0)
		words->token_type = APPEND;
	else if (ft_strncmp(words->word, ">", 2) == 0)
		words->token_type = WRITE;
	else if (ft_strncmp(words->word, "<", 2) == 0)
		words->token_type = READ;
	else
		words->token_type = WORD;
}
	
void	add_word_type(t_words *words)
{
	while (words != NULL)
	{
		identify_word_type(words);
		words = words->next;
	}
}

void	add_node_type(t_tree_node *node)
{
	if (node->word_list->token_type == PIPE_CHAR)
		node->node_type = PIPE;
	else
		node->node_type = COMMAND;
}
