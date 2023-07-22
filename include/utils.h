#ifndef UTILS_H
#define UTILS_H

#include "define.h"

/* is */
bool	is_space(int c);
bool	is_only_space(const char *str);
bool	is_special_char(int c);
bool	is_quotation(int c);
bool	is_quote_node(t_words *node);
bool	is_redirect(const t_token_type type);
bool	is_token_type_quotation(t_token_type type);
bool	is_type_in_word_list(t_words *word_list, t_token_type word_type);
bool	is_only_null_char_node(t_words *word_list);
bool	is_assignment_pattern(t_tree_node *node);
bool	is_in_equal(const char *str);

/* strdup */
char	*strdup_n(const char *src, size_t n);
char	*strdup_word(const char *str);
char	*strdup_env(const char *str);

/* new */
t_words	*new_word_node(const char *str);
t_words	*new_word_node_n(const char *str, size_t n, bool flag);
t_words	*new_ifs_node(void);
t_words	*new_redirect_node(t_token_type type);
t_words	*new_null_node_and_free_words(t_words *words, bool *err_flag);

/* count */
size_t	count_word_size(const char *str);
size_t	count_new_word_size(char *word);
size_t	count_to_front_of_c(char *str, int c);
size_t	count_env_size(const char *str);
size_t	count_map_size(t_env **map);

/* free */
void	*free_str(char *str);
void	*free_all_word_list(t_words *word_list);
void	*free_all_tree_node(t_tree_node *root);
void	*free_word_node(t_words *word_node);
void	*free_env(t_env *env);
void	*free_hash_map(t_env **hash_map);

/* get */
t_tree_node	*get_leftmost_node(t_tree_node *node);
t_token_type get_quote_type(int c);
t_token_type	get_delimiter_type(const char *str);
t_words		*get_next_start_word(t_words *words);
const char	*get_env_position(const char *str);

/* hash */
int		hash(int c);

/* ifs func */
bool	is_ifs(int c, t_data *data);
bool	is_in_ifs_char(const char *str, t_data *data);
size_t	strlen_ifs(const char *str, t_data *data);
size_t	strlen_to_ifs(const char *str, t_data *data);

/* other */
bool	print_fmt_err_syntax(char *unexpected_token);
void	*reverse_flag(bool *flag);

#endif
