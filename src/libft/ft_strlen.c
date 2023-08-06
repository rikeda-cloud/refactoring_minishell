/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:00:44 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/06 15:00:44 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

size_t	ft_strlen(const char *str)
{
	size_t	counter;

	if (str == NULL)
		return (0);
	counter = 0;
	while (*str++ != '\0')
		counter++;
	return (counter);
}
