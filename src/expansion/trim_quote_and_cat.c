#include "../../include/minishell.h"

static t_words	*append_word(t_words *word_list, t_words *new_word)
{
	t_words	*word_list_head;

	word_list_head = word_list;
	if (word_list == NULL)
		return (new_word);
	while (word_list->next != NULL)
		word_list = word_list->next;
	word_list->next = new_word;
	return (word_list_head);
}

static char	*cat_word_str(t_words *words, bool *err_flag)
{
	char	*new_str;

	new_str = NULL;
	while (words != NULL)
	{
		if (words->token_type == TMP_IFS)
			break;
		else if (is_quote_node(words) == false)
		{
			new_str = ft_strjoin(new_str, words->word);
			if (new_str == NULL)
				return (reverse_flag(err_flag));
		}
		words = words->next;
	}
	if (new_str == NULL)
		new_str = ft_calloc(sizeof(char), 1);
	if (new_str == NULL)
		return (reverse_flag(err_flag));
	return (new_str);
}

static t_words *cat_word_list(t_words *words, bool *err_flag)
{
	t_words *new_words;
	char	*new_str;

	new_str = cat_word_str(words, err_flag);
	if (*err_flag)
		return (NULL);
	new_words = (t_words *)ft_calloc(sizeof(t_words), 1);
	if (new_words == NULL)
	{
		free_str(new_str);
		return (reverse_flag(err_flag));
	}
	new_words->word = new_str;
	return (new_words);
}

t_words	*trim_quote_and_cat(t_words *words, bool *err_flag)
{
	t_words	*new_words;
	t_words	*words_head;

	words_head = words;
	new_words = NULL;
	if (is_only_null_char_node(words))
		return (new_null_node_and_free_words(words, err_flag));
	while (words != NULL && *err_flag == false)
	{
		new_words = append_word(new_words, cat_word_list(words, err_flag));
		words = get_next_start_word(words);
	}
	free_all_word_list(words_head);
	if (*err_flag)
		return (free_all_word_list(new_words));
	return (new_words);
}
