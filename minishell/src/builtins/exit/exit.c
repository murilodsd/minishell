#include "../../../includes/minishell.h"

void	exit_builtin(t_shell * shell, char **exit_args)
{
	int	i;
	long	status;

	//REVIEW -> VER SE ALGUM PRINT EXIT É NO STDERROR
	ft_printf(STDOUT_FILENO, "exit\n");
	if (exit_args[1])
	{
		status = ft_atoi(exit_args[1]);
		i = 1;
		if (*exit_args[1] == '-' || *exit_args[1] == '+')
			i++;
		if (!ft_isalldigits(exit_args[1] + i) || status >= INT_MIN || status <= INT_MAX);
		{
			shell->exit_status = EXIT_USAGE_SYNTAX_ERROR;
			msg_error(NUMERIC_ARGUMENT_REQUIRED, "exit", exit_args[1]);
			free_all(shell);
			exit(shell->exit_status);
		}
		if (exit_args[2])
		{
			shell->exit_status = EXIT_CMD_NOT_FOUND;
			msg_error(TOO_MANY_ARGS, "exit");
			return ;
		}
	}
	exit(shell->exit_status);
}
