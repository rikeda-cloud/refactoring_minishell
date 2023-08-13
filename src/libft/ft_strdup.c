/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:00:32 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/13 14:17:29 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_strdup(const char *s1)
{
	char				*ptr;
	char				*tmp_ptr;

	if (s1 == NULL)
		return (NULL);
	ptr = (char *)ft_calloc(sizeof(char), ft_strlen(s1) + 1);
	if (ptr == NULL)
		return (NULL);
	tmp_ptr = ptr;
	while (*s1 != '\0')
		*ptr++ = *s1++;
	*ptr = '\0';
	return (tmp_ptr);
}
