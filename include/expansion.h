/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:56:54 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/12 12:50:15 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H

# include "define.h"

t_words	*split_str_by_quote(char *str);
t_words	*split_word_list_by_dallor_str(t_words *word_list, t_data *data);
void	variable_expansion(t_words *words, t_data *data);
void	word_split(t_words *word_list, t_data *data, bool flag);
t_words	*trim_quote_and_cat(t_words *word, bool *err_flag);

void	expansion_tree(t_tree_node *node, t_data *data);
t_words	*expansion_normal_pattern(t_tree_node *node, bool *err_flag);
t_words	*expansion_assignment_pattern(t_tree_node *node, bool *err_flag);
t_words	*expansion_node(t_tree_node *node, bool assign_flag, t_data *data);
t_words	*expansion_heredoc_node(t_tree_node *node, bool *err_flag);

bool	is_in_ifs_char(const char *str, t_data *data);
size_t	strlen_ifs(const char *str, t_data *data);
size_t	strlen_to_ifs(const char *str, t_data *data);

void	change_quote_mode(int *mode, t_token_type type);
char	*replace_all_env(char *line, t_token_type type, t_data *data);
char	*replace(char *str, char *target, const char *new_word);
void	delete_last_dallor(t_words *words, t_data *data);
void	delete_null_word_node_in_tree(t_tree_node *node);

bool	is_assignment_pattern(t_tree_node *node);
bool	is_do_word_split_pattern(bool flag, const char *str);

#endif
