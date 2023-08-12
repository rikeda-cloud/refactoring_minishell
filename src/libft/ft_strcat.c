/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:00:26 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/12 12:52:33 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_strcat(char *dst, const char *src)
{
	char	*dst_top_ptr;

	if (dst == NULL)
		return (NULL);
	else if (src == NULL)
		return (dst);
	dst_top_ptr = dst;
	while (*dst != '\0')
		dst++;
	while (*src != '\0')
		*dst++ = *src++;
	return (dst_top_ptr);
}
