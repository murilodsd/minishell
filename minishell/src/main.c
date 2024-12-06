#include "../includes/minishell.h"

int	g_signal = NONE;

 int	main(int argc, char **argv, char **envp)
{
	t_shell		*shell;

	if (argc != 1)
	{
		ft_printf(STDERR_FILENO, "minishell: too many arguments\n", argv[1]);
		return (EXIT_USAGE_SYNTAX_ERROR);
	}
	init_data(&shell, argc, argv, envp);
	while (1)
	{
		shell->cmd = readline("minishell$ ");
		if (!shell->cmd)
			handle_ctrl_d(shell);
		if (g_signal == CTRL_C)
			handle_ctrl_c(shell);
		if (shell->cmd && shell->cmd[0] != '\0')
		{
			add_history(shell->cmd);
			handle_input(shell->cmd, shell);
			if (shell->cmd)
				free(shell->cmd);
		}
	}
	return (0);
}
