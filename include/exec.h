#ifndef EXEC_H
#define EXEC_H

#include "define.h"

char 		*str_to_command(t_tree_node *root);
void		command_loop(t_tree_node *root, t_data *data);

int			parents(t_tree_node *root,  pid_t pid, int prevfd, int *pipefd);
void		last_parents(t_tree_node *root, pid_t pid, int prevfd);
void		child_wait(t_tree_node *root, t_tree_node *first_command);
int			do_command(t_tree_node *root, int prevfd, int heredoc_fd);
void		do_last_command(t_tree_node *root, int prevfd, int heredoc_fd);

char		*get_path(char *separgv);
char		*do_file_access(char *file);

void		do_redirect(t_words *sign, t_words *filename);
void		do_append(t_words *filename);
void		redirect_check(t_words *head);

t_words		*delete_redirect_node(t_words *word_list);
int			heredoc_check(t_words *head, t_data *data);
int			heredoc(const char *delimiter, t_token_type type, t_data *data);
bool		apparently_heredoc(t_tree_node *node);
int			*heredoc_loop(t_tree_node *root, t_data *data);

t_words		*delete_redirect_node(t_words *word_list);

#endif
