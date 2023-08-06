/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:56:39 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/06 17:14:57 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "define.h"

void	my_echo(t_words *word_list, int fd, t_data *data, bool exit_flag);
void	my_pwd(t_words *word_list, int fd, t_data *data, bool exit_flag);
void	my_export(t_words *word_list, int fd, t_data *data, bool exit_flag);
void	my_env(t_words *word_list, int fd, t_data *data, bool exit_flag);
void	my_unset(t_words *word_list, int fd, t_data *data, bool exit_flag);
bool	my_exit(t_words *word_list, int fd, t_data *data, bool exit_flag);
void	my_cd(t_words *word_list, int fd, t_data *data, bool exit_flag);

bool	calc_exit_status(const char *str, t_data *data);
bool	is_option_n(const char *str);
t_words	*get_not_option_node(t_words *word_list);
char	*change_plus_equal_to_word(char *str, t_data *data);
bool	is_in_plus_equal(const char *str);
char	*skip_plus_equal(char *str);

void	print_all_env(void (*fmt)(char *, char *, int), int fd, t_data *data);
void	fmt_export(char *key, char *value, int fd);
void	fmt_env(char *key, char *value, int fd);

t_cd	try_chdir(const char *path, t_cd *crr_mode);
t_cd	try_chdir_cdpath(char **cdpath, char *str);
t_cd	try_chdir_with_cdpath(t_env **map, char *str);

#endif
