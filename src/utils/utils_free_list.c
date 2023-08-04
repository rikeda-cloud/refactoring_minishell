#include "../../include/minishell.h"

void	*free_char_array(char **char_list)
{
	size_t	idx;

	idx = 0;
	if (char_list == NULL)
		return (NULL);
	while (char_list[idx] != NULL)
		free_str(char_list[idx++]);
	free(char_list);
	return (NULL);
}

void	*free_int_array(int *array)
{
	free(array);
	return (NULL);
}
