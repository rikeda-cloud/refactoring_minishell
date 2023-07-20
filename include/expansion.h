#ifndef EXPANSION_H
#define EXPANSION_H

#include "define.h"

t_words	*split_str_by_quote(char *str);
void	variable_expansion(t_words *words, bool *err_flag);
void	split_word_list_by_ifs(t_words *word_list, bool *err_flag);
t_words	*trim_quote_and_cat(t_words *words, bool *err_flag);

/* expansion */
void	expansion_tree(t_tree_node *node, bool *faild_flag);
t_words	*expansion_normal_pattern(t_tree_node *node, bool *err_flag);
t_words	*expansion_assignment_pattern(t_tree_node *node, bool *err_flag);
t_words *expansion_heredoc_node(t_tree_node *node, bool *err_flag);
t_words	*append_word_list(t_words *dst, t_words *src, bool *err_flag);

/* ifs func */
bool	is_ifs(int c);
bool	is_in_ifs_char(const char *str);
size_t	strlen_ifs(const char *str);
size_t	strlen_to_ifs(const char *str);

/* other */
const char	*get_env_position(const char *str);
void	change_quote_mode(int *mode, t_token_type type);
char	*replace(char *str, char *target, const char *new_word);

#endif
