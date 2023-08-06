#include "../../include/minishell.h"

static void	heredoc_not_save_data(const char *delimiter)
{
	char	*line;

	while (true)
	{
		line = readline(HEREDOC_PROMPT);
		if (line == NULL)
			break ;
		if (is_same_to_newline(line, delimiter) || g_sig_mode == HEREDOC_C_MODE)
		{
			free(line);
			break ;
		}
		free(line);
	}
}

static bool	empty_heredoc(t_words *word_list, t_words *ctrl_operator)
{
	t_words	*prev_word;

	prev_word = word_list;
	if (word_list != NULL)
		word_list = word_list->next;
	while (word_list != NULL && g_sig_mode != HEREDOC_C_MODE)
	{
		if (is_redirect(prev_word->token_type))
		{
			if (is_redirect(word_list->token_type))
				return (true);
		}
		if (prev_word->token_type == HEREDOC)
			heredoc_not_save_data(word_list->word);
		prev_word = word_list;
		word_list = word_list->next;
	}
	if (is_redirect(prev_word->token_type) && ctrl_operator != NULL)
		return (true);
	else if (is_redirect(prev_word->token_type) && ctrl_operator == NULL)
		return (true);
	return (false);
}

bool	apparently_heredoc(t_tree_node *node)
{
	g_sig_mode = HEREDOC_MODE;
	node = get_leftmost_node(node);
	if (node->prev == NULL)
		return (empty_heredoc(node->word_list, NULL));
	if (empty_heredoc(node->word_list, node->prev->word_list))
		return (true);
	node = node->prev->right;
	while (node->prev->prev != NULL && g_sig_mode != HEREDOC_C_MODE)
	{
		if (empty_heredoc(node->word_list, node->prev->word_list))
			return (true);
		node = node->prev->prev->right;
	}
	if (g_sig_mode != HEREDOC_C_MODE)
		return (empty_heredoc(node->word_list, NULL));
	return (true);
}
