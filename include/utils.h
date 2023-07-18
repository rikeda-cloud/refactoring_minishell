#ifndef UTILS_H
#define UTILS_H

#include "define.h"

/* is */
bool	is_space(int c);
bool	is_special_char(int c);
bool	is_quotation(int c);
bool	is_redirect(const t_token_type type);
bool	is_token_type_quotation(t_token_type type);
bool	is_type_in_word_list(t_words *word_list, t_token_type word_type);

/* strdup */
char	*strdup_n(const char *src, size_t n);
char	*strdup_word(const char *str);

/* count */
size_t	count_word_size(const char *str);
size_t	count_new_word_size(char *word);
size_t	count_to_front_of_c(char *str, int c);
size_t	count_env_size(const char *str);

/* hash */
int		hash(int c);

/* free */
void	*free_all_word_list(t_words *word_list);
void	*free_all_tree_node(t_tree_node *root);
void	free_word_node(t_words *word_node);

/* other */
t_tree_node	*get_leftmost_node(t_tree_node *node);
bool	print_fmt_err_syntax(char *unexpected_token);
void	reverse_flag(bool *flag);

#endif
