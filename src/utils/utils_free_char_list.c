#include "../../include/minishell.h"

void	*free_char_list(char **char_list)
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
