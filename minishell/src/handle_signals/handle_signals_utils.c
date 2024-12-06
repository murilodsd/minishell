#include "../../includes/minishell.h"

void	handle_ctrl_d(t_shell *shell)
{
	ft_printf(STDIN_FILENO, "exit\n");
	shell->exit_status = EXIT_SUCCESS;
	free_exit(shell);
}

void	handle_ctrl_c(t_shell *shell)
{
	shell->exit_status = 130;
	clear_token_list(shell);
	clear_heredoc_list(shell);
}

void	handle_hd_sigint(int signal)
{
	if (signal == SIGINT)
	{
		ft_printf(STDIN_FILENO, "\n");
		g_signal = CTRL_C_HD;
	}
}
