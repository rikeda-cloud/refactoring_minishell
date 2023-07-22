#include "../../include/minishell.h"

static bool	is_need_to_be_escaped(int c)
{
	size_t	idx;

	idx = 0;
	while (NEED_TO_BE_ESCAPED[idx] != '\0')
	{
		if (NEED_TO_BE_ESCAPED[idx++] == c)
			return (true);
	}
	return (false);

}

void	fmt_export(char *key, char *value, int fd)
{
	if (ft_strcmp(key, "_") != 0)
	{
		ft_putstr_fd("declare -x ", fd);
		ft_putstr_fd(key, fd);
		ft_putstr_fd("=\"", fd);
		while (*value != '\0')
		{
			if (is_need_to_be_escaped(*value))
				ft_putchar_fd('\\', fd);
			ft_putchar_fd(*value++, fd);
		}
		ft_putstr_fd("\"\n", fd);
	}
}

void	fmt_env(char *key, char *value, int fd)
{
	ft_putstr_fd(key, fd);
	ft_putchar_fd('=', fd);
	ft_putstr_fd(value, fd);
	ft_putchar_fd('\n', fd);
}
