#include "../../../includes/minishell.h"

static long	ft_atol(char *nptr, long *n)
{
	long	signal;

	if (!ft_strcmp("-9223372036854775808", nptr))
		return (*n = LONG_MIN);
	signal = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '+')
		nptr++;
	else if (*nptr == '-')
	{
		nptr++;
		signal = -1;
	}
	*n = 0;
	while (ft_isdigit(*nptr))
	{
		if (*n > *n * 10 + (*nptr - '0'))
			return (FALSE);
		*n = *n * 10 + (*nptr - '0');
		nptr++;
	}
	*n = *n * signal;
	return (TRUE);
}

void	exit_builtin(t_shell * shell, char **exit_args)
{
	int			i;
	long	*status;

	//REVIEW -> VER SE ALGUM PRINT EXIT É NO STDERROR
	status = ft_calloc(1, sizeof(long));
	check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), \
		status, "Getcwd failed");
	ft_printf(STDOUT_FILENO, "exit\n");
	if (exit_args[1])
	{
		i = 0;
		if (*exit_args[1] == '-' || *exit_args[1] == '+')
			i++;
		if (!ft_isalldigits(exit_args[1] + i) || !ft_atol(exit_args[1], status))
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
			ft_lstremove_mem_node(&(shell->mem_allocation.ptr_mem_list), status);
			return ;
		}
		shell->exit_status = *status % 256;
		if (*status < 0)
			shell->exit_status = 256 - shell->exit_status;
	}
	free_exit(shell);
}
