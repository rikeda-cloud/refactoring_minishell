#ifndef PIPEX_H
# define PIPEX_H

#include "define.h"

void	do_last_cmd(char *cmd);
void	do_first_mid_cmd(char	*cmd, int *pipefd);
void	last_cmd(char *outfile, char *infile, char *argv, int prev_fd);
void	mid_cmd(char	*cmd, int *pipefd, int prev_fd);
void	first_cmd(char *infile, char *argv, int *pipefd);

void	do_close(int fd);
int	    do_pipe(int	*pipefd);
pid_t	do_fork(void);
int	    do_dup2(int pipefd, int fd);
char	*do_file_access(char *file);

int	    heredoc(char *limiter);
char	**do_split(char *str, char c);
char	*do_strjoin(char *s1, char *s2);

void	no_pipe(char **argv);
void	nopipe_file(char **argv);
void	do_nopipe_cmd(char *path, char **separgv);
void	only_heredoc(char **argv);

int	    parents(int *pipefd, size_t i, int argc, int prev_fd);
void	wait_child(char **argv, size_t i);

char	*get_path(char *separgv);

void	check_argc(int argc);
void	choice_case_cmd(int argc, char **argv);

#endif
