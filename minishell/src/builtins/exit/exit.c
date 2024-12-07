#include "../../../includes/minishell.h"

static bool	ft_atol(char *nptr, long *n)
{
	long	signal;

	if (!ft_strcmp("-9223372036854775808", nptr))
	{
		*n = LONG_MIN;
		return (TRUE);
	}
	signal = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
		signal = -1;
	if (*nptr == '+' || *nptr == '-')
		nptr++;
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
		if (!ft_isalldigits(exit_args[1] + i) || !ft_atol(exit_args[1], status) || exit_args[1][0] == '\0')
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
	}
	free_exit(shell);
}

/* #define MAX_TOKENS 100

char **parse_input(char *input) {
    char **tokens = malloc(MAX_TOKENS * sizeof(char *));
    char *token;
    int i = 0;

    if (!tokens) {
        ft_printf(2, "Allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(input, " \t\r\n\a");
    while (token != NULL) {
        tokens[i] = token;
        i++;

        if (i >= MAX_TOKENS) {
            ft_printf(2, "Too many tokens\n");
            exit(EXIT_FAILURE);
        }

        token = strtok(NULL, " \t\r\n\a");
    }
    tokens[i] = NULL;
    return tokens;
} */

/* int	main(int argc, char **argv, char **envp)
{
	t_shell		*shell;
	char **args;
	(void)envp;
	//REVIEW -> APAGAR LINHA DEBAIXO
	//char *envp1[] = {"aaa=primeira", "var2=1", "var3=", "var", NULL};
	//char *args[] = {"cd", "src", NULL};
	init_data(&shell, argc, argv, envp);
	shell->exit_status = EXIT_CMD_NOT_FOUND;
	ft_printf(1, "Setei o status como %d\n", shell->exit_status);
	// char *args0[] = {"exit", "9223372036854775808", NULL};
	// exit_builtin(shell, args0);
	// ft_printf(1, "%d\n", shell->exit_status);
	// char *args1[] = {"exit", "-9223372036854775809", NULL};
	// exit_builtin(shell, args1);
	ft_printf(1, "%d\n", shell->exit_status);
	while (1)
	{
		shell->cmd = readline("minishell$ ");
		check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), \
			shell->cmd, "Read line failed");
		if (shell->cmd[0] != '\0')
		{
			args = parse_input(shell->cmd);
			check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), \
			args, "Read line failed");
			if (!ft_strcmp(args[0], "cd"))
				cd_builtin(shell, args);
			else if (!ft_strcmp(args[0], "exit"))
				exit_builtin(shell, args);
			else if (!ft_strcmp(args[0], "pwd"))
				pwd_builtin(shell);
			ft_printf(1, "exit_status: %d\n", shell->exit_status);
			//pwd_builtin(shell);
			add_history(shell->cmd);
			//handle_input(shell->cmd);
			//free(shell->cmd);
			ft_lstremove_mem_node(&(shell->mem_allocation.ptr_mem_list), shell->cmd);
		}
	}
	free_exit_error(shell, 0, "teste");
 	return (0);
} */
