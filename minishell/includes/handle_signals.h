/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signals.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:55:24 by dramos-j          #+#    #+#             */
/*   Updated: 2024/12/09 22:15:36 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_SIGNALS_H
# define HANDLE_SIGNALS_H
# include "minishell.h"

// *************************** FUNCTION PROTOTYPES ********************* //

// handle_signals.c
void	handle_signals(void);
void	sigint_handler(int signal);
void	reset_sig_int_and_quit(void);
void	reset_sig_int_ignore_sig_quit(void);
void	ignore_sig_int_and_quit(void);

// handle_signals_utils.c
void	handle_ctrl_d(t_shell *shell);
void	handle_ctrl_c(t_shell *shell);
void	handle_ctrl_c_hd(t_shell *shell);
void	handle_heredoc_signal(int signal);

#endif
