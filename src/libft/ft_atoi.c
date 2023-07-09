#include "../../include/minishell.h"

static bool	is_spaces(char c)
{
	if (c == '\t' || c == '\n' || c == '\r')
		return (true);
	else if (c == '\v' || c == '\f' || c == ' ')
		return (true);
	return (false);
}

static int	plus_or_minus(char const *str)
{
	bool	flag_isspace;
	int		flag_plus_minus;
	bool	flag_plus_minus_find;

	flag_isspace = true;
	flag_plus_minus = 0;
	flag_plus_minus_find = false;
	while (!('0' <= *str && *str <= '9'))
	{
		if (flag_isspace == true)
			flag_isspace = is_spaces(*str);
		if (flag_isspace == false)
		{
			if (flag_plus_minus_find == false && (*str == '-' || *str == '+'))
			{
				flag_plus_minus_find = true;
				if (*str == '-')
					flag_plus_minus = 1;
			}
			else
				return (-1);
		}
		str++;
	}
	return (flag_plus_minus);
}

static long int	atoi_plus(const char *nptr)
{
	long int	tmp;
	long int	long_max_div_10;

	long_max_div_10 = LONG_MAX / 10;
	tmp = 0;
	while ('0' <= *nptr && *nptr <= '9')
	{
		if (long_max_div_10 < tmp)
			return (LONG_MAX);
		if (tmp == long_max_div_10 && (*nptr - '0' > LONG_MAX % 10))
			return (LONG_MAX);
		tmp *= 10;
		tmp += *nptr - '0';
		nptr++;
	}
	return (tmp);
}

static long int	atoi_minus(const char *nptr)
{
	long int	tmp;
	long int	long_min_div_10;

	long_min_div_10 = LONG_MIN / 10;
	tmp = 0;
	while ('0' <= *nptr && *nptr <= '9')
	{
		if (long_min_div_10 > tmp)
			return (LONG_MIN);
		if (tmp == long_min_div_10 && (*nptr - '0' > -(LONG_MIN % 10)))
			return (LONG_MIN);
		tmp *= 10;
		tmp -= (*nptr - '0');
		nptr++;
	}
	return (tmp);
}

int	ft_atoi(char *str)
{
	int		plus_minus_mode;

	plus_minus_mode = plus_or_minus(str);
	if (plus_minus_mode == -1)
		return (0);
	while (!('0' <= *str && *str <= '9'))
		str++;
	if (plus_minus_mode == 1)
		return ((int)atoi_minus(str));
	else
		return ((int)atoi_plus(str));
}
