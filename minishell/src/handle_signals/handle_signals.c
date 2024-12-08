/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 14:42:26 by dramos-j          #+#    #+#             */
/*   Updated: 2024/12/08 15:44:01 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_signal;

void	sigint_handler(int signal)
{
	if (signal == SIGINT)
	{
		rl_replace_line("", 0);
		rl_on_new_line();
		ft_printf(STDOUT_FILENO, "\n");
		rl_redisplay();
		g_signal = SIGINT;
	}
}

void	handle_signals(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
}

void	reset_sig_int_and_quit(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

void	reset_sig_int_ignore_sig_quit(void)
{
	signal(SIGINT, handle_heredoc_signal);
	signal(SIGQUIT, SIG_IGN);
}

void	ignore_sig_int_and_quit(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}
