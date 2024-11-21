#include "../../../includes/minishell.h"

void	echo_builtin(t_shell *shell, char **args)
{
	bool	new_line;
	int	i;

	new_line = TRUE;
	i = 1;
	while (args[i])
	{
		if (args[i][0] != '-')
			break ;
		if (!ft_str_in_set(args[i] + 1, "n"))
			break;
		new_line = FALSE;
		i++;
	}
	while (args[i])
	{
		ft_printf(STDOUT_FILENO,"%s", args[i]);
		i++;
		if (args[i])
			ft_printf(STDOUT_FILENO, " ");	
	}
	if (new_line)
		ft_printf(STDOUT_FILENO, "\n");
	shell->exit_status = EXIT_SUCCESS;
}

/* int	main(int argc, char **argv, char **envp)
{
	t_shell		*shell;
	(void)envp;
	//REVIEW -> APAGAR LINHA DEBAIXO
	char *envp1[] = {"aaa=primeira", "var2=1", "var3=", "var", NULL};
	init_data(&shell, argc, argv, envp1);
	char *args[] = {"echo", "", NULL};
	echo_builtin(args);
	char *args0[] = {"echo", "comquebra", NULL};
	echo_builtin(args0);
	char *args00[] = {"echo", NULL};
	echo_builtin(args00);
	char *args01[] = {"echo", "-n", NULL};
	echo_builtin(args01);
	char *args1[] = {"echo", "-n", "semquebra", NULL};
	echo_builtin(args1);
	char *args2[] = {"echo", "-nnnnn", "semquebra", NULL};
	echo_builtin(args2);
	char *args3[] = {"echo", "-1", "-n", "-nnn", "comquebra", NULL};
	echo_builtin(args3);
	char *args5[] = {"echo", "-n", "-1", "-nnn", "semquebra", NULL};
	echo_builtin(args5);t_shell		*shell;
	char *args4[] = {"echo", "-nnnnn", "-n", "-nnn", "fimsemquebra", NULL};
	echo_builtin(args4);
	free_exit_error(shell, 0, "teste");
	return (0);
} */