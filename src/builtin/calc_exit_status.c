/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_exit_status.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:57:12 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/13 14:15:40 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static bool	is_over_long_max(const char *str)
{
	long int	tmp;
	long int	long_max_div_10;

	long_max_div_10 = LONG_MAX / 10;
	tmp = 0;
	while (*str == ' ')
		str++;
	if (*str == '-')
		return (false);
	if (*str == '+')
		str++;
	while ('0' <= *str && *str <= '9')
	{
		if (long_max_div_10 < tmp)
			return (true);
		if (tmp == long_max_div_10 && (*str - '0' > LONG_MAX % 10))
			return (true);
		tmp *= 10;
		tmp += (*str++ - '0');
	}
	return (false);
}

static bool	is_under_long_min(const char *str)
{
	long int	tmp;
	long int	long_min_div_10;

	long_min_div_10 = LONG_MIN / 10;
	tmp = 0;
	while (*str == ' ')
		str++;
	while (*str != '-')
		return (false);
	str++;
	while ('0' <= *str && *str <= '9')
	{
		if (long_min_div_10 > tmp)
			return (true);
		if (tmp == long_min_div_10 && (*str - '0' > -(LONG_MIN % 10)))
			return (true);
		tmp *= 10;
		tmp -= (*str++ - '0');
	}
	return (false);
}

static bool	is_not_number_str(const char *str)
{
	while (*str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		str++;
	if (!('0' <= *str && *str <= '9'))
		return (true);
	while ('0' <= *str && *str <= '9')
		str++;
	if (*str == '\0')
		return (false);
	else
		return (true);
}

static int	get_eight_bit(long int number)
{
	int		eight_bit;
	size_t	bit;

	eight_bit = 0;
	bit = 0;
	while (bit < 8)
	{
		if (number & (1 << bit))
			eight_bit += (1 << bit);
		bit++;
	}
	return (eight_bit);
}

bool	calc_exit_status(const char *str, t_data *data)
{
	if (is_not_number_str(str))
		return (err_exit(str, &data->err_code));
	else if (is_over_long_max(str) || is_under_long_min(str))
		return (err_exit(str, &data->err_code));
	else
	{
		data->err_code = get_eight_bit(ft_atoi(str));
		return (false);
	}
}
