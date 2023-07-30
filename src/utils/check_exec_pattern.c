#include "include/minishell.h"

typedef enum e_exec_type
{
	NORMAL = 0,
	NONE,
	ENV,
	ENV_PIPE,
	BUILTIN,
	BUILTIN_PIPE,
}	t_exec_type;

t_tree_node		*get_leftmost_node(t_tree_node *node)
{
	while (node->left != NULL)
		node = node->left;
	return (node);
}

bool	is_builtin_command(const char *command)
{
	if (ft_strcmp(command, "cd") == 0)
		return (true);
	else if (ft_strcmp(command, "echo") == 0)
		return (true);
	else if (ft_strcmp(command, "env") == 0)
		return (true);
	else if (ft_strcmp(command, "exit") == 0)
		return (true);
	else if (ft_strcmp(command, "export") == 0)
		return (true);
	else if (ft_strcmp(command, "pwd") == 0)
		return (true);
	else if (ft_strcmp(command, "unset") == 0)
		return (true);
	else
		return (false);
}

t_exec_type	check_exec_pattern(t_tree_node *node)
{
	t_words	*word_list;

	node = get_leftmost_node(node);
	word_list = node->word_list;
	while (word_list != NULL)
	{
		if (is_redirect(word_list->token_type))
			word_list = word_list->next->next;
		else if (ft_strcmp(word_list->word, "env") == 0 && node->prev == NULL)
			return (ENV);
		else if (ft_strcmp(word_list->word, "env") == 0 && node->prev != NULL)
			return (ENV_PIPE);
		else if (is_builtin_command(word_list->word) && node->prev == NULL)
			return (BUILTIN);
		else if (is_builtin_command(word_list->word) && node->prev != NULL)
			return (BUILTIN_PIPE);
		else
			return (NORMAL);
	}
	return (NONE);
}
