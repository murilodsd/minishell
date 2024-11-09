#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	init_data();
	if(argc != 1 || argv[1] || !envp)
	{
		printf("Error: No arguments needed\n");
		exit(0);
	}
	while (1)
	{
		data->cmd = readline("minishell$ ");
		if (data->cmd[0] != '\0')
		{
			add_history(data->cmd);
			handle_input(data->cmd);
			parser();
			binary_tree();
			executer();
			builtins();
			free(data->cmd);
		}
	}
	return (0);
}
