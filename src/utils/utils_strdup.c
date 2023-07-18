#include "../../include/minishell.h"

char	*strdup_n(const char *src, size_t n)
{
	size_t	idx;
	char	*dest;

	idx = 0;
	dest = (char *)calloc(sizeof(char), (n + 1));
	while (idx < n)
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (dest);
}

char	*strdup_word(const char *str)
{
	char	*word;
	size_t	word_size;

	word_size = count_word_size(str);
	word = strdup_n(str, word_size);
	return (word);
}
