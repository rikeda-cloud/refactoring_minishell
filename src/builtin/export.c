/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:57:26 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/12 12:50:40 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	export_have_arg_pattern(t_words *word_list, t_data *data)
{
	while (word_list != NULL)
	{
		if (is_only_under_env(word_list->word))
			;
		else if (is_not_a_valid_identifier(word_list->word))
			err_export_valid(word_list->word, &data->err_code);
		else if (is_in_plus_equal(word_list->word))
		{
			word_list->word = change_plus_equal_to_word(word_list->word, data);
			insert_or_update_env(word_list->word, data);
		}
		else
			insert_or_update_env(word_list->word, data);
		word_list = word_list->next;
	}
}

void	my_export(t_words *word_list, int fd, t_data *data, bool exit_flag)
{
	dup2_and_close_stdout(fd, exit_flag, &data->err_flag);
	if (data->err_flag)
	{
		data->err_code = 1;
		return ;
	}
	if (word_list != NULL && ft_strcmp(word_list->word, "--") == 0)
		word_list = word_list->next;
	if (word_list == NULL)
	{
		print_all_env(fmt_export, STDOUT_FILENO, data);
		data->err_code = 0;
	}
	else
	{
		data->err_code = 0;
		export_have_arg_pattern(word_list, data);
	}
}
