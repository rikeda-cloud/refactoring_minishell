/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:57:01 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/06 15:17:52 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "define.h"

t_words		*lexer(const char *str, t_data *data);
t_tree_node	*parser(const char *str, t_data *data);

t_words		*change_str_to_word_list(const char *str, t_data *data);
void		add_words_type(t_words *words);
bool		check_not_close_quotation(const t_words *word_list);
bool		check_syntax_err_word_list(const t_words *word_list, t_data *data);

t_tree_node	*create_tree(t_words *words, t_data *data);
void		add_node_type(t_tree_node *const node);
bool		check_syntax_err_tree(t_tree_node *node, t_data *data);

#endif
