#include "../../includes/minishell.h"

void	ft_lstadd_var_ordered(t_list **lst, t_list *new);


static void	create_env_export_lst(t_shell *shell, char **envp)
{
	int		i;
	t_list	*new_node;
	t_var	*var;

	i = 0;
	while (envp[i] != NULL)
	{
		var = ft_calloc(sizeof(t_var), 1);
		check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), \
			var, "Calloc failed");
		get_new_var_name_and_value(shell, var, envp[i]);
		new_node = ft_lstnew(var);
		check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), \
			new_node, "Calloc failed");
		ft_lstadd_back(&(shell->envp_lst), new_node);
		new_node = ft_lstnew(var);
		check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), \
			new_node, "Calloc failed");
		ft_lstadd_var_ordered(&(shell->export_lst), new_node);
		i++;
	}
}

void	check_args(t_shell *shell, int argc, char **argv)
{
	if (argc != 1)
	{
		shell->exit_status = EXIT_USAGE_SYNTAX_ERROR;
		free_exit_error(shell, NO_FILE_DIRECTORY, argv[1]);
	}
}

void	 init_data(t_shell **shell, int argc, char **argv, char **envp)
{
	*shell = ft_calloc(sizeof(t_shell), 1);
	if (!(*shell))
	{
		msg_error(GENERAL_ERROR, "Calloc Error\n");
		exit(EXIT_FAILURE);
	}
	check_args(*shell, argc, argv);
	(*shell)->envp_lst = NULL;
	(*shell)->export_lst = NULL;
	(*shell)->envp_lst = NULL;
	(*shell)->export_lst = NULL;
	(*shell)->exit_status = EXIT_SUCCESS;
	//TODO - PEGAR NUMERO DO PROCESSO
	(*shell)->fd_in = 0;
	(*shell)->fd_out = 1;
	create_env_export_lst(*shell, envp);
	handle_signals();
}
