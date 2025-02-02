/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signals_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:52:23 by dramos-j          #+#    #+#             */
/*   Updated: 2024/12/10 21:52:38 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handle_ctrl_d(t_shell *shell)
{
	ft_printf(STDIN_FILENO, "exit\n");
	shell->exit_status = EXIT_SUCCESS;
	free_exit(shell);
}

void	handle_ctrl_c(t_shell *shell)
{
	shell->exit_status = EXIT_SIGINT;
	free_restart(shell);
	g_signal = 0;
}

void	handle_ctrl_c_hd(t_shell *shell)
{
	shell->exit_status = EXIT_SIGINT;
	free_restart(shell);
	g_signal = 0;
}

void	set_signals_to_here_doc(void)
{
	signal(SIGINT, handle_heredoc_signal);
	signal(SIGQUIT, SIG_DFL);
}

void	handle_heredoc_signal(int signal)
{
	if (signal == SIGINT)
	{
		ft_printf(STDOUT_FILENO, "\n");
		g_signal = SIGINT;
		close(STDIN_FILENO);
	}
}
