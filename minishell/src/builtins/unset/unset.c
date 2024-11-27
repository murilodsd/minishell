#include "../../../includes/minishell.h"

//unset -> só retorna
//unset nonexistentvariable -> só retorna
//unset USER -> apaga USER
//unset "" -> retorna

void	ft_lstremove_mem_node(t_list **lst, void *content)
{
	t_list *current;
	t_list *previous;

	if (!lst)
		return ;
	current = *lst;
	previous = NULL;
	while (current)
	{
		if (current->content == content)
		{
			if (previous)
				previous->next = current->next;
			else
				*lst = current->next;
			free(current->content);
			free(current);
			return ;
		}
		previous = current;
		current = current->next;
	}
}

void	ft_lstremove_var(t_shell *shell, t_list **lst, char *name)
{
	t_list	*current;
	t_list	*previous;
	t_var	*var;

	current = *lst;
	previous = NULL;
	while (current)
	{
		var = (t_var *)current->content;
		if (ft_strcmp(var->name, name) == 0)
		{
			if (previous)
				previous->next = current->next;
			else
				*lst = current->next;
			ft_lstremove_mem_node(&(shell->mem_allocation.ptr_mem_list), var->name);
			ft_lstremove_mem_node(&(shell->mem_allocation.ptr_mem_list), var->value);
			ft_lstremove_mem_node(&(shell->mem_allocation.ptr_mem_list), current->content);
			ft_lstremove_mem_node(&(shell->mem_allocation.ptr_mem_list), current);
			return ;
		}
		previous = current;
      		current = current->next;
	}
}

void	unset_builtin(t_shell *shell, char **unset_args)
{
		int	i;

	if (!unset_args[1])
		return ;
	else
	{
		i = 1;
		while (unset_args[i])
		{
			ft_lstremove_var(shell, &(shell->envp_lst), unset_args[i]);
			ft_lstremove_var(shell, &(shell->export_lst), unset_args[i]);
			i++;
		}
	}
	shell->exit_status = 0;
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
}

int	main(int argc, char **argv, char **envp)
{
	t_shell		*shell;
	char **args;
	(void)envp;
	//REVIEW -> APAGAR LINHA DEBAIXO
	char *envp1[] = {"aaa=primeira", NULL};
	//char *args[] = {"cd", "src", NULL};
	init_data(&shell, argc, argv, envp1);
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
			else if (!ft_strcmp(args[0], "unset"))
				unset_builtin(shell, args);
			else if (!ft_strcmp(args[0], "export"))
				export_builtin(shell, args);
			else if (!ft_strcmp(args[0], "env"))
				env_builtin(shell);
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
}
