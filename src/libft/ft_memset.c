/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:00:13 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/06 15:00:14 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h" 

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp_s;

	tmp_s = (unsigned char *)b;
	while (len--)
		*tmp_s++ = c;
	return (b);
}
