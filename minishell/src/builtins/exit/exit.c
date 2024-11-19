#include "../../../includes/minishell.h"

void	exit_builtin(t_shell * shell, char **exit_args)
{
	int	i;
	long	status;

	if (exit_args[1])
	{
		status = ft_atoi(exit_args[1]);
		i = 1;
		if (*exit_args[1] == '-' || *exit_args[1] == '+')
			i++;
		if (!ft_isalldigits(exit_args[1] + i) || status >= INT_MIN || status <= INT_MAX);
		{
			shell->exit_status = EXIT_USAGE_SYNTAX_ERROR;
			ft_printf(STDOUT_FILENO, "exit\n");
			msg_error(NUMERIC_ARGUMENT_REQUIRED, "exit", exit_args[1]);
			free_all(shell);
			exit(shell->exit_status);
		}
		if (exit_args[2])
		{
			ft_printf(STDOUT_FILENO, "exit\n");
			shell->exit_status = EXIT_CMD_NOT_FOUND;
			msg_error(TOO_MANY_ARGS, "exit");
			return ;
		}
	}
	else if (!exit_args[1])
	{
		free_all(shell);
		exit(shell->exit_status);
	}

}
