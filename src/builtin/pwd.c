#include "../../include/minishell.h"

void	my_pwd(t_words *word_list, int fd, t_data *data)
{
	(void)word_list;
	if (fd != STDOUT_FILENO)
	{
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	if (data->crr_dir != NULL)
	{
		ft_putendl_fd(data->crr_dir, STDOUT_FILENO);
		data->err_code = 0;
	}
	else
	{
		print_err1(ERR_CRR_DIR_NOT_EXIST);
		data->err_code = 1;
	}
}
