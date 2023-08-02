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
bool	is_do_not_word_split_pattern(bool flag, const char *str);
bool	is_only_under_env(const char *str);
bool	is_not_a_valid_identifier(const char *str);
bool	is_add_and_assign(const char *str);

/* strdup */
char	*strdup_n(const char *src, size_t n);
char	*strdup_env(const char *str, bool *err_flag);

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
size_t	count_assignment_word(t_words *word_list);

/* free */
void	*free_str(char *str);
void	*free_double_str(char *str1, char *str2);
void	*free_char_list(char **char_list);
void	*free_all_word_list(t_words *word_list);
void	*free_all_tree_node(t_tree_node *root);
void	*free_word_node(t_words *word_node);
t_words	*free_word_node_get_next_node(t_words *word_node);
void	*free_env(t_env *env);
void	*free_hash_map(t_env **hash_map);
void	*free_all_data(t_data *data);

/* get */
t_tree_node	*get_leftmost_node(t_tree_node *node);
t_token_type get_quote_type(int c);
t_token_type	get_delimiter_type(const char *str);
t_words		*get_next_start_word(t_words *words);
const char	*get_env_position(const char *str);

/* hash */
int		hash(int c);

/* append */
t_words	*append_word_node(t_words *list, t_words *word_node);
t_words	*append_with_flag(t_words *list, t_words *word_node, bool err_flag);
t_words	*append_str_to_word_list(t_words *word_list, const char *str);

/* print_err */
bool	print_err1(const char *arg1);
bool	print_err2(const char *arg1, const char *arg2);
bool	print_err3(const char *arg1, const char *arg2, const char *arg3);
bool	err_syntax(const char *unexpected_token, int *err_code);
bool	err_no_file(const char *not_exist_home, int *err_code);
bool	err_no_home(int *err_code);
bool	err_many_arg(const char *command, int *err_code);
bool	err_exit(const char *str, int *err_code);
bool	err_export_valid(const char *str, int *err_code);

/* signal */
void	minishell_handler(int signal);

/* other */
void	*reverse_flag(bool *flag);

#endif
