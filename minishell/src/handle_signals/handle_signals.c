#include "../../includes/minishell.h"

void	sigint_handler(int signal)
{
	if (signal == SIGINT)
	{
		rl_replace_line("", 0);
		rl_on_new_line();
		ft_printf(STDIN_FILENO, "\n");
		rl_redisplay();
	}
}

void	handle_signals(void)
{
	printf("handle_signals\n");

	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
}
