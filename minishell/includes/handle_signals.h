#ifndef HANDLE_SIGNALS_H
# define HANDLE_SIGNALS_H
# include "minishell.h"

// ********************************* GLOBAL VARIABLE ********************* //

extern int	g_signal;

// handle_signals.c
void	handle_signals(void);
void	sigint_handler(int signal);
void	reset_sig_int_and_quit(void);
void	reset_sig_int_ignore_sig_quit(void);
void	ignore_sig_int_and_quit(void);

#endif
