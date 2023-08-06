#include "../../include/minishell.h"

static void	identify_word_type(t_words *const words)
{
	if (words->word == NULL)
		words->token_type = WORD;
	else if (ft_strncmp(words->word, "|", 2) == 0)
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

void	add_words_type(t_words *word_list)
{
	while (word_list != NULL)
	{
		identify_word_type(word_list);
		word_list = word_list->next;
	}
}

void	add_node_type(t_tree_node *const node)
{
	if (node->word_list->token_type == PIPE_CHAR)
		node->node_type = PIPE;
	else
		node->node_type = COMMAND;
}
