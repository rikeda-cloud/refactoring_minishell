/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:57:29 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/13 14:15:48 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static bool	is_need_to_be_escaped(int c)
{
	size_t	idx;

	idx = 0;
	while (NEED_TO_BE_ESCAPED[idx] != '\0')
	{
		if (NEED_TO_BE_ESCAPED[idx++] == c)
			return (true);
	}
	return (false);
}

void	fmt_export(char *key, char *value, int fd)
{
	if (ft_strcmp(key, "_") == 0)
		return ;
	ft_putstr_fd("declare -x ", fd);
	if (value == NULL)
		ft_putendl_fd(key, fd);
	else
	{
		ft_putstr_fd(key, fd);
		ft_putstr_fd("=\"", fd);
		while (*value != '\0')
		{
			if (is_need_to_be_escaped(*value))
				ft_putchar_fd('\\', fd);
			ft_putchar_fd(*value++, fd);
		}
		ft_putstr_fd("\"\n", fd);
	}
}

void	fmt_env(char *key, char *value, int fd)
{
	if (value == NULL)
		return ;
	ft_putstr_fd(key, fd);
	ft_putchar_fd('=', fd);
	ft_putstr_fd(value, fd);
	ft_putchar_fd('\n', fd);
}
