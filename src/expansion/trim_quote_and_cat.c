#include "../../include/minishell.h"

bool	is_quote_node(t_words *node)
{
	if (node->token_type == TMP_SINGLE_QUOTE)
		return (true);
	if (node->token_type == TMP_DOUBLE_QUOTE)
		return (true);
	return (false);
}

t_words *cat_words(t_words *words)
{
	t_words *new_words;
	char	*new_str;

	if (words == NULL)
		return (NULL);
	new_str = NULL;
	new_words = (t_words *)ft_calloc(sizeof(t_words), 1);
	new_words->token_type = WORD;
	while (words != NULL)
	{
		if (words->token_type == TMP_IFS)
			break ;
		else if (is_quote_node(words) == false)
			new_str = ft_strjoin(new_str, words->word);
		words = words->next;
	}
	new_words->word = new_str;
	if (new_words->word == NULL)
		new_words->word = (char *)ft_calloc(sizeof(char), 1);
	return (new_words);
}

t_words		*get_next_start_word(t_words *words)
{
	while (words != NULL && words->token_type != TMP_IFS)
		words = words->next;
	if (words == NULL)
		return (NULL);
	else
		words = words->next;
	return (words);
}

t_words		*trim_quote_and_cat(t_words *words)
{
	t_words	*new_words;
	t_words	*new_words_top_ptr;
	t_words	*tmp_words;

	new_words = cat_words(words);
	tmp_words = get_next_start_word(words);
	if (tmp_words == NULL)
		return (new_words);
	new_words_top_ptr = new_words;
	while (tmp_words != NULL)
	{
		new_words->next = cat_words(tmp_words);
		tmp_words = get_next_start_word(tmp_words);
		new_words = new_words->next;
	}
	return (new_words_top_ptr);
}
