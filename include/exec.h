/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:56:48 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/06 17:13:07 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "define.h"

void	cmd_loop(t_tree_node *root, t_data *data);

void	child_wait(t_tree_node *root, t_table *table, t_data *data);

void	do_normal_cmd(t_tree_node *root, int pre, t_table *table, t_data *data);
int		do_cmd(t_tree_node *root, int prevfd, t_table *table, t_data *data);
void	do_lst_cmd(t_tree_node *root, int prevfd, t_table *table, t_data *data);

bool	do_builtin_cmd(t_words *cmd, t_data *data, bool exit_flag);
void	do_builtin_cmd_alone_without_env(t_tree_node *root, t_data *data);

char	*get_path(char *separgv, t_data *data);

bool	apparently_heredoc(t_tree_node *node);
t_table	*heredoc_loop(t_tree_node *root, t_data *data);

t_words	*delete_redirect_node(t_words *word_list);

char	**change_word_list_to_cmd(t_words *word_list);
bool	is_builtin_cmd(const char *cmd);
bool	is_builtin_cmd_alone_without_env(t_tree_node *node);
bool	is_last_cmd(t_tree_node *root);
bool	is_same_to_newline(const char *have_newline_str, const char *str);

void	exec_normal_cmd_child_proc(t_words *word_list, t_data *data);
void	exec_builtin_cmd_child_proc(t_words *word_list, t_data *data);

bool	redirect_check(t_words *word_list, bool can_exit_flag);
void	redirect_read(t_words *fname, bool exit_flag, bool *err_flag);
void	redirect_write(t_words *fname, bool exit_flag, bool *err_flag);
void	redirect_append(t_words *fname, bool exit_flag, bool *err_flag);

int		do_open_read(char *filename, bool exit_flag, bool *err_flag);
int		do_open_write(char *filename, bool exit_flag, bool *err_flag);
int		do_open_append(char *filename, bool exit_flag, bool *err_flag);
void	do_dup2(int old_fd, int new_fd, bool exit_flag, bool *err_flag);
void	do_close(int close_fd, bool exit_flag, bool *err_flag);
void	do_pipe(int *pipefd);
pid_t	do_fork(void);
void	do_execve(char *path, char **separgv, char **my_environ);

#endif
