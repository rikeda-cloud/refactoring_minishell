#ifndef EXPANSION_H
#define EXPANSION_H

#include "define.h"

bool	expansion_tree(t_tree_node *node);
t_words	*split_str_by_quote(char *str);
void	variable_expansion(t_words *word);
void	split_word_list_by_ifs(t_words *words);
t_words	*trim_quote_and_cat(t_words *word);

char	*replace(char *str, char *target, const char *new_word);
char	*strdup_env(const char *str);

void	change_quote_mode(int *mode, t_token_type type);

const char	*search_env_position(const char *str);
#endif
