#include "../../include/minishell.h"

static char	*free_and_return_null(char *str)
{
	free(str);
	return (NULL);
}

static int	check_lf_in_buffer(char *buffer, char *tmp)
{
	if (tmp == NULL)
		return (1);
	while (*buffer != '\0')
	{
		if (*buffer++ == '\n')
			return (1);
	}
	return (0);
}

static char	*remove_before_lf(char *tmp, char *buffer)
{
	unsigned long long	i;
	unsigned long long	j;

	i = 0;
	j = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\0')
		buffer[0] = '\0';
	else
	{
		i++;
		while (buffer[i] != '\0')
			buffer[j++] = buffer[i++];
		buffer[j] = '\0';
	}	
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	ssize_t		size;
	char		*tmp;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	tmp = sp_join(NULL, buffer);
	if (check_lf_in_buffer(buffer, tmp))
		return (remove_before_lf(tmp, buffer));
	while (1)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size <= 0 && tmp[0] == '\0')
			return (free_and_return_null(tmp));
		else if (size <= 0 && tmp[0] != '\0')
			return (remove_before_lf(tmp, buffer));
		buffer[size] = '\0';
		if (check_lf_in_buffer(buffer, "NOT NULL"))
			return (remove_before_lf(sp_join(tmp, buffer), buffer));
		tmp = sp_join(tmp, buffer);
		if (tmp == NULL)
			return (NULL);
	}
}
