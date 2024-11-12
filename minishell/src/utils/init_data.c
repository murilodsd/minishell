#include "../../includes/minishell.h"

void	check_args(t_shell *shell, int argc, char **argv)
{
	if (argc != 1)
	{
		shell->exit_status = EXIT_USAGE_SYNTAX_ERROR;
		free_exit_error(shell, NO_FILE_DIRECTORY, argv[1]);
	}
}

void	init_data(t_shell **shell, int argc, char **argv, char **envp)
{
	printf("Initializing data\n");
	*shell = ft_calloc(sizeof(t_shell), 1);
	if (!(*shell))
	{
		msg_error(GENERAL_ERROR, "Calloc Error\n");
		exit(EXIT_FAILURE);
	}
	check_args(*shell, argc, argv);
	//TODO - INICIALIZAR ENVS
	(void)envp;
	(*shell)->exit_status = EXIT_SUCCESS;
	//TODO - PEGAR NUMERO DO PROCESSO
	(*shell)->fd_in = STDIN_FILENO;
	(*shell)->fd_out = STDOUT_FILENO;
	handle_signals();
}
