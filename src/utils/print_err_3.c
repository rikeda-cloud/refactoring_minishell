/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:55:03 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/13 14:17:57 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
