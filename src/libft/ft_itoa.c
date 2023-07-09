#include "../../include/minishell.h"

static int	is_minus(long int long_n)
{
	return (long_n < 0);
}

static size_t	count_digit(long int long_n)
{
	size_t	counter;

	counter = 0;
	if (long_n == 0)
		return (1);
	while (long_n)
	{
		counter++;
		long_n /= 10;
	}
	return (counter);
}

static int	calc_div_number(int digit)
{
	if (digit == 1)
		return (1);
	else
		return (10 * calc_div_number(digit - 1));
}

static void	fill_ptr(char *ptr, long int long_n, int flag_minus, int digit)
{
	int	div_number;

	if (flag_minus)
		*ptr++ = '-';
	while (digit)
	{
		div_number = calc_div_number(digit);
		*ptr++ = (long_n / div_number) + '0';
		long_n %= div_number;
		digit--;
	}
	*ptr = '\0';
}

char	*ft_itoa(int n)
{
	int			flag_minus;
	long int	digit;
	char		*ptr;
	long int	long_n;

	long_n = (long int)n;
	flag_minus = is_minus(long_n);
	if (flag_minus)
		long_n = -long_n;
	digit = count_digit(long_n);
	ptr = (char *)malloc(sizeof(char) * (flag_minus + digit + 1));
	if (ptr == NULL)
		return (NULL);
	fill_ptr(ptr, long_n, flag_minus, digit);
	return (ptr);
}
