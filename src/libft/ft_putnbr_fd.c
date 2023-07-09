#include "../../include/minishell.h"

static long long int	abs_and_put_minus(long long int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		return (-n);
	}
	return (n);
}

static long long int	check_digit(long long int n)
{
	long long int	digit;

	digit = 1;
	while (!(n < 10))
	{
		n /= 10;
		digit *= 10;
	}
	return (digit);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long int	digit;
	char			c;
	long long int	tmp_n;

	tmp_n = (long long int)n;
	tmp_n = abs_and_put_minus(tmp_n, fd);
	digit = check_digit(tmp_n);
	while (digit)
	{
		c = (tmp_n / digit) + '0';
		ft_putchar_fd(c, fd);
		tmp_n %= digit;
		digit /= 10;
	}
}
