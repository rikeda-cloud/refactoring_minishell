#ifndef BUILTIN_H
#define BUILTIN_H

#include "define.h"

void	my_echo(t_words *word_list, int fd, t_data *data);
void	my_pwd(t_words *word_list, int fd, t_data *data);
void	my_export(t_words *word_list, int fd, t_data *data);
void	my_env(t_words *word_list, int fd, t_data *data);
void	my_unset(t_words *word_list, int fd, t_data *data);
void	my_exit(t_words *word_list, int fd, t_data *data);
void	my_cd(t_words *word_list, int fd, t_data *data);

bool	calc_exit_status(const char *str, t_data *data);
bool	is_option(const char *str, int option_c);
bool	is_option_n(const char *str);
bool	is_option_n_pattern(t_words *word_list);
t_words	*get_not_option_node(t_words *word_list);

void	print_all_env(void (*fmt)(char *,char *,int), int fd, t_data *data);
void	fmt_export(char *key, char *value, int fd);
void	fmt_env(char *key, char *value, int fd);

#endif
