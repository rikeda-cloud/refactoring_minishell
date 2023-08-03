#ifndef EXEC_H
#define EXEC_H

#include "define.h"

void		command_loop(t_tree_node *root, t_data *data);
void		child_wait(t_tree_node *root, t_tree_node *first_cmd, t_data *data);

int			do_cmd(t_tree_node *root, int prevfd, int heredocfd, t_data *data);
void		do_lst_cmd(t_tree_node *root, int prevfd, int heredocfd, t_data *data);
char		**change_word_list_to_cmd(t_words *word_list);

bool		do_builtin_cmd(t_words *cmd, t_data *data);
void		do_builtin_cmd_alone_without_env(t_words *cmd, t_data *data);

char		*get_path(char *separgv, t_data *data);
char		*do_file_access(char *file, t_data *data);
void		do_redirect(t_words *sign, t_words *filename, t_data *data);
void		do_append(t_words *filename);
void		redirect_check(t_words *head, t_data *data);

void		heredoc_not_save_data(const char *delimiter);
bool		apparently_heredoc(t_tree_node *node);
int			*heredoc_loop(t_tree_node *root, t_data *data);

t_words		*delete_redirect_node(t_words *word_list);

t_exec_type	check_exec_pattern(t_tree_node *node);
bool		is_builtin_cmd(const char *cmd);
bool		is_builtin_cmd_alone_without_env(t_tree_node *node);
bool		is_last_cmd(t_tree_node *root);
bool		is_same_to_newline(const char *have_newline_str, const char *str);

#endif
