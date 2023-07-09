#ifndef UTILS_H
#define UTILS_H

#include "define.h"

bool	is_space(int c);
bool	is_space_word(char *str);
bool	is_special_char(int c);
bool	is_quotation(int c);
bool	is_only_quotation(char *word);

bool	is_redirect(t_token_type type);
bool	is_syntax_error_words(t_words *words);
bool	is_syntax_error_tree(t_tree_node *node);

char	*strdup_n(char *src, size_t n);
char	*strdup_word(char *str);

t_words	*del_word(t_words *word);

size_t	count_word_size(char *str);
size_t	count_new_word_size(char *word);
size_t	count_to_front_of_c(char *str, int c);

bool	check_in_type(t_words *words, t_token_type word_type);
int		hash(int c);

#endif
