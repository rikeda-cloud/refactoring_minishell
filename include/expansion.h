#ifndef EXPANSION_H
#define EXPANSION_H

#include "define.h"

t_words	*split_str_by_quote(char *str);
void	variable_expansion(t_words *words, t_data *data);
void	split_word_list_by_ifs(t_words *word_list, t_data *data);
t_words	*trim_quote_and_cat(t_words *words, bool *err_flag);

/* expansion */
void	expansion_tree(t_tree_node *node, t_data *data);
t_words	*expansion_normal_pattern(t_tree_node *node, bool *err_flag);
t_words	*expansion_assignment_pattern(t_tree_node *node, bool *err_flag);
t_words	*expansion_node(t_tree_node *node, bool assign_flag, t_data *data);
t_words *expansion_heredoc_node(t_tree_node *node, bool *err_flag);
t_words	*do_all_expansion(char *str, t_data *data);
t_words	*do_not_word_split_expansion(char *str, t_data *data);

/* ifs func */
bool	is_in_ifs_char(const char *str, t_data *data);
size_t	strlen_ifs(const char *str, t_data *data);
size_t	strlen_to_ifs(const char *str, t_data *data);

/* other */
void	change_quote_mode(int *mode, t_token_type type);
char	*replace(char *str, char *target, const char *new_word);
char	*replace_all_env(char *str, t_data *data);
void	del_null_word_node_in_tree(t_tree_node *node);

#endif
