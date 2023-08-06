#ifndef BUILTIN_H
#define BUILTIN_H

#include "define.h"

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

void	print_all_env(void (*fmt)(char *,char *,int), int fd, t_data *data);
void	fmt_export(char *key, char *value, int fd);
void	fmt_env(char *key, char *value, int fd);


t_cd	try_chdir(const char *path, t_cd *crr_mode);
t_cd	try_chdir_cdpath(char **cdpath, char *str);
t_cd	try_chdir_with_cdpath(t_env **map, char *str);

#endif
