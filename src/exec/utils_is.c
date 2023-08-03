#include "../../include/minishell.h"

bool	is_builtin_cmd(const char *cmd)
{
	if (ft_strcmp(cmd, "cd") == 0)
		return (true);
	else if (ft_strcmp(cmd, "echo") == 0)
		return (true);
	else if (ft_strcmp(cmd, "env") == 0)
		return (true);
	else if (ft_strcmp(cmd, "exit") == 0)
		return (true);
	else if (ft_strcmp(cmd, "export") == 0)
		return (true);
	else if (ft_strcmp(cmd, "pwd") == 0)
		return (true);
	else if (ft_strcmp(cmd, "unset") == 0)
		return (true);
	else
		return (false);
}

bool	is_last_cmd(t_tree_node *root)
{
	if (root->prev == NULL)
		return (true);
	else  if (root->prev->prev == NULL && root != root->prev->left)
		return (true);
	else
		return (false);
}

bool	is_same_to_newline(const char *have_newline_str, const char *str)
{
	size_t	idx;

	idx = 0;
	while (have_newline_str[idx] != '\0' && have_newline_str[idx] != '\n')
	{
		if (have_newline_str[idx] != str[idx])
			return (false);
		idx++;
	}
	idx = 0;
	while (str[idx] != '\0')
	{
		if (have_newline_str[idx] != str[idx])
			return (false);
		idx++;
	}
	return (true);
}

