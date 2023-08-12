/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_do_not_word_split_pattern.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:59:27 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/12 12:52:04 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static bool	is_in_dallor_front_of_equal(const char *str)
{
	while (*str != '\0' && *str != '=')
	{
		if (*str++ == '$')
			return (true);
	}
	return (false);
}

bool	is_do_word_split_pattern(bool flag, const char *str)
{
	if (flag == false)
		return (true);
	else if (is_in_equal(str) == false)
		return (true);
	else if (is_in_dallor_front_of_equal(str))
		return (true);
	else
		return (false);
}
