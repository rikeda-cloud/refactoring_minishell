/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_builtin_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:58:28 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/06 15:59:53 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	do_dup(int fd)
{
	int	new_fd;

	new_fd = dup(fd);
	if (new_fd < 0)
		perror_exit("dup", 1);
	return (new_fd);
}

bool	do_builtin_cmd(t_words *cmd, t_data *data, bool exit_flag)
{
	bool	can_exit_flag;

	can_exit_flag = false;
	if (ft_strcmp(cmd->word, "cd") == 0)
		my_cd(cmd->next, STDOUT_FILENO, data, exit_flag);
	else if (ft_strcmp(cmd->word, "echo") == 0)
		my_echo(cmd->next, STDOUT_FILENO, data, exit_flag);
	else if (ft_strcmp(cmd->word, "env") == 0)
		my_env(cmd->next, STDOUT_FILENO, data, exit_flag);
	else if (ft_strcmp(cmd->word, "exit") == 0)
		can_exit_flag = my_exit(cmd->next, STDOUT_FILENO, data, exit_flag);
	else if (ft_strcmp(cmd->word, "export") == 0)
		my_export(cmd->next, STDOUT_FILENO, data, exit_flag);
	else if (ft_strcmp(cmd->word, "pwd") == 0)
		my_pwd(cmd->next, STDOUT_FILENO, data, exit_flag);
	else if (ft_strcmp(cmd->word, "unset") == 0)
		my_unset(cmd->next, STDOUT_FILENO, data, exit_flag);
	return (can_exit_flag);
}

static void	reset_fd_and_close(int *keep_fd, bool *err_flag)
{
	do_dup2(keep_fd[0], STDIN_FILENO, true, err_flag);
	do_close(keep_fd[0], true, err_flag);
	do_dup2(keep_fd[1], STDOUT_FILENO, true, err_flag);
	do_close(keep_fd[1], true, err_flag);
}

void	do_builtin_cmd_alone_without_env(t_tree_node *root, t_data *data)
{
	int	tmp_err_code;
	int	keep_fd[2];

	keep_fd[0] = do_dup(STDIN_FILENO);
	keep_fd[1] = do_dup(STDOUT_FILENO);
	if (redirect_check(root->word_list, false))
	{
		reset_fd_and_close(keep_fd, &data->err_flag);
		data->err_code = 1;
		return ;
	}
	do_dup2(keep_fd[0], STDIN_FILENO, true, &data->err_flag);
	do_close(keep_fd[0], true, &data->err_flag);
	root->word_list = delete_redirect_node(root->word_list);
	if (ft_strcmp(root->word_list->word, "exit") == 0)
		ft_putendl_fd("exit", STDERR_FILENO);
	if (do_builtin_cmd(root->word_list, data, false))
	{
		tmp_err_code = data->err_code;
		exit(tmp_err_code);
	}
	do_dup2(keep_fd[1], STDOUT_FILENO, true, &data->err_flag);
	do_close(keep_fd[1], true, &data->err_flag);
}
