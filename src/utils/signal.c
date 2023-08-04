#include "../../include/minishell.h"

static void	handler_normal(void)
{
	return ;
}

static void	handler_readline(void)
{
	ft_putchar_fd('\n', STDOUT_FILENO);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_sig_mode = ENTER_CTRL_C_MODE;
}

static void	handler_heredoc(void)
{
	close(STDIN_FILENO);
	g_sig_mode = ENTER_CTRL_C_MODE;
}

static void	handler_exec(void)
{
	ft_putchar_fd('\n', STDOUT_FILENO);
}

void	minishell_handler(int signal)
{
	if (signal != SIGINT)
		return ;
	else if (g_sig_mode == NORMAL)
		handler_normal();
	else if (g_sig_mode == READLINE_MODE || g_sig_mode == ENTER_CTRL_C_MODE)
		handler_readline();
	else if (g_sig_mode == HEREDOC_MODE)
		handler_heredoc();
	else if (g_sig_mode == EXEC_MODE)
		handler_exec();
}
