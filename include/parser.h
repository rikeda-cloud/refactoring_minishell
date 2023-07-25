#ifndef PARSER_H
#define PARSER_H

#include "define.h"

/* ----------------- lexer --------------------------- */
t_words		*lexer(const char *str, t_data *data);

t_words		*change_str_to_word_list(const char *str, t_data *data);
void		identify_word_type(t_words *const words);
void		add_words_type(t_words *words);
bool		check_not_close_quotation(const t_words *word_list);
bool		check_syntax_err_words(const t_words *word_list, t_data *data);

/* ----------------- parser --------------------------- */

t_tree_node	*parser(t_words *word_list, t_data *data);

t_tree_node	*create_tree(t_words *words, t_data *data);
void		add_node_type(t_tree_node * const node);
bool		check_syntax_err_tree(t_tree_node *node, t_data *data);

#endif
