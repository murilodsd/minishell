/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signals_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:52:23 by dramos-j          #+#    #+#             */
/*   Updated: 2024/12/08 17:27:57 by dramos-j         ###   ########.fr       */
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
	free_restart(shell);
	g_signal = 0;
}

void	handle_ctrl_c_hd(t_shell *shell)
{
	shell->exit_status = 130;
	free_restart(shell);
	g_signal = 0;
}

void	handle_heredoc_signal(int signal)
{
	if (signal == SIGINT)
	{
		ft_printf(STDIN_FILENO, "\n");
		g_signal = SIGINT;
	}
}
