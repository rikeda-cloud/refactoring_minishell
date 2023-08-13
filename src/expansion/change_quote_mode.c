/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_quote_mode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:59:07 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/13 14:16:59 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	change_quote_mode(int *mode, t_token_type type)
{
	if (*mode == SINGLE_Q_MODE || *mode == DOUBLE_Q_MODE)
		*mode = NOT_Q_MODE;
	else if (type == TMP_SINGLE_QUOTE)
		*mode = SINGLE_Q_MODE;
	else
		*mode = DOUBLE_Q_MODE;
}
