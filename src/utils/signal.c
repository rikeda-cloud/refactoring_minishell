/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:01:30 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/06 15:01:31 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	minishell_handler(int signal)
{
	if (signal != SIGINT)
		return ;
	else if (g_sig_mode == HEREDOC_MODE || g_sig_mode == HEREDOC_C_MODE)
		g_sig_mode = HEREDOC_C_MODE;
	else if (g_sig_mode == EXEC_MODE)
		ft_putchar_fd('\n', STDOUT_FILENO);
	else if (g_sig_mode == READLINE_MODE || g_sig_mode == READLINE_C_MODE)
	{
		g_sig_mode = READLINE_C_MODE;
		ft_putchar_fd('\n', STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

int	heredoc_handler(void)
{
	if (g_sig_mode == HEREDOC_C_MODE)
	{
		rl_replace_line("", 0);
		rl_done = 1;
	}
	return (0);
}
