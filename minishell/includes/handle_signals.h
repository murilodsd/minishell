#ifndef HANDLE_SIGNALS_H
# define HANDLE_SIGNALS_H
# include "minishell.h"

// ********************************* GLOBAL VARIABLE ********************* //

extern int	g_signal;

// ********************************* DEFINES **************************** //

typedef enum signal_type
{
	CTRL_C,
	CTRL_C_HD,
	CTRL_BACKSLASH,
	CTRL_BACKSLASH_HD,
	CTRL_D,
	CTRL_D_HD
}	t_signal_type;

// *************************** FUNCTION PROTOTYPES ********************* //

// handle_signals.c
void	handle_signals(void);
void	sigint_handler(int signal);
void	reset_sig_int_and_quit(void);
void	reset_sig_int_ignore_sig_quit(void);
void	ignore_sig_int_and_quit(void);

// handle_signals_utils.c
void	handle_ctrl_d(t_shell *shell);

#endif
