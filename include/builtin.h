#ifndef BUILTIN_H
#define BUILTIN_H

#include "define.h"

void	my_echo(t_words *word_list, int fd);
void	my_pwd(t_words *word_list, int fd);
void	my_export(t_words *word_list, int fd);
void	my_env(t_words *word_list, int fd);
void	my_unset(t_words *word_list, int fd);
void	my_exit(t_words *word_list, int fd);
void	my_cd(t_words *word_list, int fd);

int		calc_exit_status(char *str);
bool	is_option(char *str, int option_c);
bool	is_option_n(t_words *word_list);

#endif
