#ifndef PARSER_H
#define PARSER_H

#include "define.h"

/* ----------------- lexer --------------------------- */
t_words		*lexical_analysis(char *str);

size_t		count_new_word_size(char *word);
size_t		count_word_size(char *str);
t_words		*change_str_to_words(char *str);
void		add_word_type(t_words *words);
bool		check_not_close_quotation(t_words *words);

int	    ft_strncmp(const char *s1, const char *s2, size_t n);

/* ----------------- parser --------------------------- */

t_tree_node	*create_tree(t_words *words);
void		add_node_type(t_tree_node *node);

#endif
