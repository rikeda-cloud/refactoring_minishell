/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:57:21 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/12 12:50:38 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	my_env(t_words *word_list, int fd, t_data *data, bool exit_flag)
{
	(void)exit_flag;
	dup2_and_close_stdout(fd, true, NULL);
	while (word_list != NULL && is_in_equal(word_list->word))
	{
		insert_or_update_env(word_list->word, data);
		word_list = word_list->next;
	}
	if (word_list == NULL)
		print_all_env(fmt_env, STDOUT_FILENO, data);
	else
		exec_normal_cmd_child_proc(word_list, data);
}
