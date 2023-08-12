/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:00:21 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/12 12:52:31 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_putstr_fd(const char *s, int fd)
{
	if (s != NULL)
	{
		if (write(fd, s, ft_strlen(s)) == -1)
			perror("Error");
	}
}
