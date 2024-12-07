/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signals_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:52:23 by dramos-j          #+#    #+#             */
/*   Updated: 2024/12/07 15:52:24 by dramos-j         ###   ########.fr       */
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
}

void	handle_ctrl_c_hd(t_shell *shell)
{
	open("/dev/tty", O_RDONLY);
	shell->exit_status = 130;
	free_restart(shell);
	g_signal = NONE;
}

void	handle_hd_sigint(int signal)
{
	if (signal == SIGINT)
	{
		ft_printf(STDIN_FILENO, "\n");
		g_signal = CTRL_C_HD;
		close(STDIN_FILENO);
	}
}
