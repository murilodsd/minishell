#include "../../includes/minishell.h"

extern int	g_signal;

/**
 * sigint_handler - Manipula o sinal SIGINT (Ctrl-C).
 * @signal: Número do sinal recebido (deve ser SIGINT).
 *
 * Este manipulador é chamado quando o usuário pressiona Ctrl-C no shell.
 * Ele limpa a linha atual, move o cursor para uma nova linha e exibe o
 * prompt novamente, garantindo que o shell continue rodando.
 */

void	sigint_handler(int signal)
{
	if (signal == SIGINT)
	{
		rl_replace_line("", 0);
		rl_on_new_line();
		ft_printf(STDIN_FILENO, "\n");
		rl_redisplay();
		g_signal = signal;
	}
}

/**
 * handle_signals - Configura sinais para o modo interativo do shell.
 *
 * Define sigint_handler como manipulador para SIGINT e ignora SIGQUIT.
 * Esta configuração garante que Ctrl-C exiba um novo prompt e Ctrl-\ seja ignorado.
 */

/**
 * handle_signals - Configura sinais para o modo interativo do shell.
 *
 * Define sigint_handler como manipulador para SIGINT e ignora SIGQUIT.
 * Esta configuração garante que Ctrl-C exiba um novo prompt e Ctrl-\ seja ignorado.
 */

void	handle_signals(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
}


/**
 * reset_sig_int_and_quit - Restaura o comportamento padrão para SIGINT e SIGQUIT.
 *
 * Use esta função antes de executar programas externos no shell,
 * permitindo que os sinais SIGINT (Ctrl-C) e SIGQUIT (Ctrl-\) funcionem normalmente.
 */

void	reset_sig_int_and_quit(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

/**
 * reset_sig_int_ignore_sig_quit - Restaura SIGINT ao comportamento padrão e ignora SIGQUIT.
 *
 * Esta função pode ser usada em situações onde Ctrl-C deve funcionar normalmente,
 * mas Ctrl-\ continue sendo ignorado.
 */

void	reset_sig_int_ignore_sig_quit(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_IGN);
}

/**
 * ignore_sig_int_and_quit - Configura sinais para ignorar SIGINT e SIGQUIT.
 *
 * Use esta função para impedir que interrupções por Ctrl-C ou Ctrl-\ ocorram
 * durante seções críticas do código.
 */

void	ignore_sig_int_and_quit(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}
