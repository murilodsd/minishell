/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signals_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:52:23 by dramos-j          #+#    #+#             */
/*   Updated: 2024/12/08 11:15:16 by dramos-j         ###   ########.fr       */
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
	shell->exit_status = 130;
	clear_token_list(shell);
	clear_heredoc_list(shell);
	g_signal = NONE;
}

void	handle_ctrl_c_hd(t_shell *shell)
{
	close(shell->heredoc->fd_heredoc);
	free_restart(shell);
	handle_signals();
}

void	handle_hd_sigint(int signal)
{
	if (signal == SIGINT)
	{
		g_signal = CTRL_C_HD;
		ft_printf(STDIN_FILENO, "\n");
		close(STDIN_FILENO);
	}
}
