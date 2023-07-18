#ifndef PARSER_H
#define PARSER_H

#include "define.h"

/* ----------------- lexer --------------------------- */
t_words		*lexer(const char *str);

t_words		*change_str_to_word_list(const char *str);
void		add_words_type(t_words *words);
bool		check_syntax_err_words(t_words *word_list);
bool		check_not_close_quotation(const t_words *words);

int			ft_strncmp(const char *s1, const char *s2, size_t n);

/* ----------------- parser --------------------------- */

t_tree_node	*parser(t_words *word_list);
t_tree_node	*create_tree(t_words *words);
void		add_node_type(t_tree_node * const node);
bool		check_syntax_err_tree(t_tree_node *node);

#endif
