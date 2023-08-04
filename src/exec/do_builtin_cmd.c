#include "../../include/minishell.h"

bool    do_builtin_cmd(t_words *cmd, t_data *data)
{
	bool	can_exit_flag;

	can_exit_flag = false;
	if (ft_strcmp(cmd->word, "cd") == 0)
		my_cd(cmd->next, STDOUT_FILENO, data);
	else if (ft_strcmp(cmd->word, "echo") == 0)
		my_echo(cmd->next, STDOUT_FILENO, data);
	else if (ft_strcmp(cmd->word, "env") == 0)
		my_env(cmd->next, STDOUT_FILENO, data);
	else if (ft_strcmp(cmd->word, "exit") == 0)
		can_exit_flag = my_exit(cmd->next, STDOUT_FILENO, data);
	else if (ft_strcmp(cmd->word, "export") == 0)
		my_export(cmd->next, STDOUT_FILENO, data);
	else if (ft_strcmp(cmd->word, "pwd") == 0)
		my_pwd(cmd->next, STDOUT_FILENO, data);
	else if (ft_strcmp(cmd->word, "unset") == 0)
		my_unset(cmd->next, STDOUT_FILENO, data);
	return (can_exit_flag);
}

void	do_builtin_cmd_alone_without_env(t_tree_node *root, t_data *data)
{
	int		tmp_err_code;

	apparently_heredoc(root);
	redirect_check(root->word_list, data);
	root->word_list = delete_redirect_node(root->word_list);
	if (ft_strcmp(root->word_list->word, "exit") == 0)
		ft_putendl_fd("exit", STDERR_FILENO);
	if (do_builtin_cmd(root->word_list, data))
	{
		tmp_err_code = data->err_code;
		free_all_data(data);
		exit(tmp_err_code);
	}
}
