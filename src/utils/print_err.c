#include "../../include/minishell.h"

bool	print_err1(const char *arg1)
{
	ft_putendl_fd(arg1, STDERR_FILENO);
	return (true);
}

bool	print_err2(const char *arg1, const char *arg2)
{
	ft_putstr_fd(arg1, STDERR_FILENO);
	ft_putendl_fd(arg2, STDERR_FILENO);
	return (true);
}

bool	print_err3(const char *arg1, const char *arg2, const char *arg3)
{
	ft_putstr_fd(arg1, STDERR_FILENO);
	ft_putstr_fd(arg2, STDERR_FILENO);
	ft_putendl_fd(arg3, STDERR_FILENO);
	return (true);
}

bool	err_syntax(const char *unexpected_token, int *err_code)
{
	print_err3(ERR_SYNTAX, unexpected_token, ERR_SYNTAX_CLOSE);
	*err_code = 2;
	return (true);
}

bool	err_no_file(const char *not_exist_home, int *err_code)
{
	print_err3(ERR_NO_FILE, not_exist_home, ERR_NO_FILE_CLOSE);
	*err_code = 1;
	return (true);
}

bool	err_no_home(int *err_code)
{
	print_err1(ERR_NO_HOME);
	*err_code = 1;
	return (true);
}

bool	err_many_arg(const char *command, int *err_code)
{
	print_err3(ERR_MANY_ARG, command, ERR_MANY_ARG_CLOSE);
	*err_code = 1;
	return (true);
}

bool	err_exit(const char *str, int *err_code)
{
	print_err3(ERR_EXIT, str, ERR_EXIT_CLOSE);
	*err_code = 2;
	return (true);
}

bool	err_export_valid(const char *str, int *err_code)
{
	print_err3(ERR_EXPORT_VALID, str, ERR_EXPORT_VALID_CLOSE);
	*err_code = 1;
	return (true);
}
