/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:57:03 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/12 12:50:20 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "define.h"

bool			is_space(int c);
bool			is_only_space(const char *str);
bool			is_special_char(int c);
bool			is_quotation(int c);
bool			is_quote_node(t_words *node);
bool			is_redirect(const t_token_type type);
bool			is_token_type_quotation(t_token_type type);
bool			is_type_in_word_list(t_words *word_list, t_token_type type);
bool			is_only_null_char_node(t_words *word_list);
bool			is_in_equal(const char *str);
bool			is_only_under_env(const char *str);
bool			is_not_a_valid_identifier(const char *str);
bool			is_add_and_assign(const char *str);
bool			is_c_in_str(const char *str, int c);

char			*strdup_n(const char *src, size_t n);
char			*strdup_env(const char *str, bool *err_flag);
char			*strdup_env_ignore_quote(const char *str, bool *err_flag);

t_words			*new_word_node(const char *str);
t_words			*new_word_node_n(const char *str, size_t n, bool flag);
t_words			*new_ifs_node(void);
t_words			*new_redirect_node(t_token_type type);
t_words			*new_null_node_and_free_words(t_words *words, bool *err_flag);

size_t			count_word_size(const char *str);
size_t			count_new_word_size(char *word);
size_t			count_to_front_of_c(char *str, int c);
size_t			count_env_size(const char *str);
size_t			count_map_size(t_env **map);
size_t			count_assignment_word(t_words *word_list);
size_t			count_number_of_cmd(t_tree_node *node);

void			*free_str(char *str);
void			*free_double_str(char *str1, char *str2);
void			*free_char_array(char **char_array);
void			*free_table(t_table *table);
void			*free_all_word_list(t_words *word_list);
void			*free_all_tree_node(t_tree_node *root);
void			*free_word_node(t_words *word_node);
t_words			*free_word_node_get_next_node(t_words *word_node);
void			*free_env(t_env *env);
t_env			*free_env_node_and_get_next_node(t_env *env);
void			*free_hash_map(t_env **hash_map);
void			*free_all_data(t_data *data);

t_tree_node		*get_leftmost_node(t_tree_node *node);
t_token_type	get_quote_type(int c);
t_token_type	get_delimiter_type(const char *str);
t_words			*get_next_start_word(t_words *words);
const char		*get_env_position(const char *str);
const char		*get_env_position_ignore_quote(const char *str);

t_words			*append_word_node(t_words *list, t_words *word_node);
t_words			*append_with_flag(t_words *list, t_words *node, bool err_flag);
t_words			*append_str_to_word_list(t_words *list, const char *str);

void			perror_exit(char *filename, int exit_status);
bool			print_err1(const char *arg1);
bool			print_err2(const char *arg1, const char *arg2);
bool			print_err3(const char *ar1, const char *ar2, const char *ar3);
bool			err_syntax(const char *unexpected_token, int *err_code);
bool			err_no_file(const char *not_exist_cmd, int *err_code);
bool			err_no_cd_file(const char *not_exist_home, int *err_code);
bool			err_no_home(int *err_code);
bool			err_many_arg(const char *command, int *err_code);
bool			err_exit(const char *str, int *err_code);
bool			err_export_valid(const char *str, int *err_code);
bool			err_no_permission(const char *no_permission, int *err_code);

void			dup2_and_close_stdin(int fd, bool exit_flag, bool *err_flag);
void			dup2_and_close_pipefd(int *fd, bool exit_flag, bool *err_flag);
void			dup2_and_close_stdout(int fd, bool exit_flag, bool *err_flag);

void			print_core_dumped(int wstatus);
void			sig_int_handler(int signal);
void			sig_quit_handler(int signal);
int				heredoc_handler(void);

char			*strjoin_path(char *sepflag, char *separgv);
char			*strjoin_path_auto_adjustment(char *sepflag, char *separgv);

void			*reverse_flag(bool *flag);
int				hash(int c);

#endif
