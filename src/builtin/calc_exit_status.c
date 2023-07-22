#include "../../include/minishell.h"

bool	is_over_long_max(const char *str)
{
	long int	tmp;
	long int	long_max_div_10;

	long_max_div_10 = LONG_MAX / 10;
	tmp = 0;
	while (*str ==  ' ')
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

bool	is_under_long_min(const char *str)
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

bool	is_not_number_str(const char *str)
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

int	get_eight_bit(long int number)
{
	int	eight_bit;
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
	{
		 printf(FMT_ERR_EXIT, str);
		 data->err_number = 2;
		 return (true);
	}
	else if (is_over_long_max(str) || is_under_long_min(str))
	{
		 printf(FMT_ERR_EXIT, str);
		 data->err_number = 2;
		 return (true);
	}
	else
	{
		data->err_number = get_eight_bit(ft_atoi(str));
		return (false);
	}
}

/* int	main (int argc,char	**argv) */
/* { */
/* 	if (argc < 2) */
/* 	{ */
/* 		printf("argc = 1\n"); */
/* 		return (0); */
/* 	} */
/* 	printf("input = %s\nexit_status = %d\n", argv[1], calc_exit_status(argv[1])); */
/* 	return (0); */
/* } */
