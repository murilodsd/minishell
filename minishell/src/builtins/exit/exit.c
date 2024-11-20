#include "../../../includes/minishell.h"

void	exit_builtin(t_shell * shell, char **exit_args)
{
	int			i;
	long long	status;

	//REVIEW -> VER SE ALGUM PRINT EXIT É NO STDERROR
	ft_printf(STDOUT_FILENO, "exit\n");
	if (exit_args[1])
	{
		status = ft_atoi(exit_args[1]);
		i = 0;
		if (*exit_args[1] == '-' || *exit_args[1] == '+')
			i++;
		printf("%ld %ld %lld", LONG_MAX, LONG_MIN, __LONG_LONG_MAX__);
		//REVIEW -> NA VERDADE PODE SER DO TAMANHO DE LONG
		if (!ft_isalldigits(exit_args[1] + i) || status < LONG_MIN || status > LONG_MAX)
		{
			shell->exit_status = EXIT_USAGE_SYNTAX_ERROR;
			msg_error(NUMERIC_ARGUMENT_REQUIRED, "exit", exit_args[1]);
			free_all(shell);
			exit(EXIT_USAGE_SYNTAX_ERROR);
		}
		if (exit_args[2])
		{
			if (shell->exit_status == EXIT_SUCCESS)
				shell->exit_status = EXIT_FAILURE;
			msg_error(TOO_MANY_ARGS, "exit");
			return ;
		}
		shell->exit_status = status % 256;
		if (status < 0)
			shell->exit_status = 256 - shell->exit_status;
	}
	free_exit(shell);
}
