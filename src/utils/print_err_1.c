/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:01:24 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/12 12:53:07 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	perror_exit(char *filename, int exit_status)
{
	perror(filename);
	exit(exit_status);
}

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

bool	print_err3(const char *ar1, const char *ar2, const char *ar3)
{
	ft_putstr_fd(ar1, STDERR_FILENO);
	ft_putstr_fd(ar2, STDERR_FILENO);
	ft_putendl_fd(ar3, STDERR_FILENO);
	return (true);
}
