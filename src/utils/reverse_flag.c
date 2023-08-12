/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:01:27 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/12 12:53:10 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	*reverse_flag(bool *flag)
{
	if (*flag == true)
		*flag = false;
	else if (*flag == false)
		*flag = true;
	return (NULL);
}
