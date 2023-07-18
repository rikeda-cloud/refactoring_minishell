#ifndef UTILS_H
#define UTILS_H

#include "define.h"

/* is */
bool	is_space(int c);
bool	is_special_char(int c);
bool	is_quotation(int c);
bool	is_redirect(const t_token_type type);

/* strdup */
char	*strdup_n(const char *src, size_t n);
char	*strdup_word(const char *str);

/* del */
t_words	*del_word(t_words *word);

/* count */
size_t	count_word_size(const char *str);
size_t	count_new_word_size(char *word);
size_t	count_to_front_of_c(char *str, int c);

/* hash */
int		hash(int c);

/* free */
void	*free_all_word_list(t_words *word_list);
void	*free_all_tree_node(t_tree_node *root);

/* other */
bool	check_in_type(t_words *words, t_token_type word_type);
t_tree_node	*get_leftmost_node(t_tree_node *node);
bool	print_fmt_err_syntax(char *unexpected_token);
void	reverse_flag(bool *flag);

#endif
