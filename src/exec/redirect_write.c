#include "../../include/minishell.h"

int do_open_write(char *filename, bool exit_flag, bool *err_flag)
{
    int fd;

    fd = open(filename, (O_RDWR | O_CREAT | O_TRUNC), 0644);
	if (fd < 0 && exit_flag == true)
        perror_exit(filename, 1);
	else if (fd < 0 && exit_flag == false)
	{
		*err_flag = true;
		perror(filename);
	}
    return(fd);
}

void    redirect_write(t_words *fname, bool exit_flag, bool *err_flag)
{
    int fd;

    fd = do_open_write(fname->word, exit_flag, err_flag);
	if (*err_flag)
		return;
    do_dup2(fd, 1, exit_flag, err_flag);
	if (*err_flag)
		return;
    do_close(fd, exit_flag, err_flag);
}
