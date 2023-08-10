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

void	sig_int_handler(int signal)
{
	(void)signal;
	if (g_sig_mode == HEREDOC_MODE || g_sig_mode == HEREDOC_C_MODE)
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

void	print_core_dumped(int wstatus)
{
	if (WCOREDUMP(wstatus))
		ft_putendl_fd(ERR_CORE_DUMPED, STDERR_FILENO);
}

void	sig_quit_handler(int signal)
{
	(void)signal;
	if (g_sig_mode == EXEC_MODE)
		g_sig_mode = EXEC_C_MODE;
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
