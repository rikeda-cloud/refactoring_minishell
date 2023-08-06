/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:55:00 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/06 15:55:01 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	err_syntax(const char *unexpected_token, int *err_code)
{
	print_err3(ERR_SYNTAX, unexpected_token, ERR_SYNTAX_CLOSE);
	*err_code = 2;
	return (true);
}

bool	err_no_file(const char *not_exist_cmd, int *err_code)
{
	print_err3(ERR_NO_FILE, not_exist_cmd, ERR_NO_FILE_CLOSE);
	*err_code = 127;
	return (true);
}

bool	err_no_cd_file(const char *not_exist_home, int *err_code)
{
	print_err3(ERR_NO_CD_FILE, not_exist_home, ERR_NO_FILE_CLOSE);
	*err_code = 1;
	return (true);
}

bool	err_no_permission(const char *no_permission, int *err_code)
{
	print_err3(ERR_NO_PERMISSION, no_permission, ERR_NO_PERMISSION_CLOSE);
	*err_code = 1;
	return (true);
}

bool	err_no_home(int *err_code)
{
	print_err1(ERR_NO_HOME);
	*err_code = 1;
	return (true);
}
