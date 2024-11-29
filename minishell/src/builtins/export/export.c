#include "../../../includes/minishell.h"

	//export var=    -> var=""
	//export var=1 var2=2 var=3    -> salva todas
	//export var 1   -> bash: export: `1': not a valid identifier     (so pode comecar com letra ou _ e no nome so pode conter letras numeros e _)
	//export var=1; export var;     -> irá manter o valor anterior de var
	//export = ->  bash: export: `=': not a valid identifier


void	ft_lstadd_var_ordered(t_list **lst, t_list *new)
{
	t_list	*node_ref;

	if (!lst || !new)
		return ;
	if (!(*lst))
		*lst = new;
	else if (ft_strcmp(((t_var *)((*lst)->content))->name, ((t_var *)((new)->content))->name) > 0)
	{
		new->next = *lst;
		*lst = new;
	}
	else
	{
		node_ref = *lst;
		while (node_ref->next && ft_strcmp(((t_var *)(node_ref->next->content))->name, ((t_var *)(new->content))->name ) < 0)
			node_ref = node_ref->next;
		if (node_ref->next == NULL)
			ft_lstlast(*lst)->next = new;
		else
		{
			new->next = node_ref->next;
			node_ref->next = new;
		}
	}
}

void	add_or_edit_var(t_shell *shell, t_var *var)
{
	if (!(var->name))
		return ;
	if (ft_lstfind_name(shell->export_lst, var->name))
		edit_var(shell, var);
	else
		add_var(shell, var);
}

void	export_var(t_shell *shell, char *export_arg)
{
	t_var	*var;

	var = (t_var *)ft_calloc(sizeof(t_var), 1);
	check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), \
			var, "Calloc failed");
	get_new_var_name_and_value(shell, var, export_arg);
	add_or_edit_var(shell, var);
}

void	print_export(void *envp)
{
	t_var	*content;

	content = (t_var *)envp;
	if (!content || !(content->name))
		return ;
	ft_printf(STDOUT_FILENO, "declare -x %s", content->name);
	if (content->value)
	{
		ft_putchar_fd('=', STDOUT_FILENO);
		ft_putchar_fd('"', STDOUT_FILENO);
		ft_printf(STDOUT_FILENO, "%s", content->value);
		ft_putchar_fd('"', STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
	}
	else
		ft_putchar_fd('\n', STDOUT_FILENO);
}

void	export_builtin(t_shell *shell, char **export_args)
{
	int	i;

	shell->exit_status = EXIT_SUCCESS;
	if (!export_args[1])
		ft_lstiter(shell->export_lst, print_export);
	else
	{
		i = 1;
		while (export_args[i])
		{
			export_var(shell, export_args[i]);
			i++;
		}
	}
}

/* int	main(int argc, char **argv, char **envp)
{
	t_shell		*shell;
	(void)envp;
	//REVIEW -> APAGAR LINHA DEBAIXO
	char *envp1[] = {"aaa=primeira", "var2=1", "var3=", "var", NULL};
	char *args[] = {"export", "", "1var=", "var2 =", "var2=2", "var3", "var=", "var4", NULL};
	init_data(&shell, argc, argv, envp1);
	export_builtin(shell, args);
	char *args0[] = {"export", NULL};
	export_builtin(shell, args0);
	char *args1[] = {"unset", "aaa", "v1var", "var3", "1VAR", "", NULL};
	unset_builtin(shell, args1);
	char *args2[] = {"export", NULL};
	export_builtin(shell, args2);
	env_builtin(shell->envp_lst);
	free_exit_error(shell, 0, "teste");
	return (0);
} */
/*
#define MAX_TOKENS 100

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
	(void)envp;
	//REVIEW -> APAGAR LINHA DEBAIXO
	(void)argc;
	(void)argv;
	char **args;
	//char *envp1[] = {"aaa=primeira", "var2=1", "var3=", "var", NULL};
	char *args00[] = {"export", "", "1var=", "var2 =", "var2=2", "var3", "var=", "var4", NULL};
	char *args00[] = {"export", "VAR+=", "VAR+=1", "var+=100", NULL};
 	init_data(&shell, argc, argv, envp);
	export_builtin(shell, args00);
	ft_printf(1, "exit_status: %d\n", shell->exit_status);
	char *args0[] = {"export", NULL};
	export_builtin(shell, args0);
	ft_printf(1, "exit_status: %d\n", shell->exit_status);
	//char *args1[] = {"unset", "aaa", "v1var", "var3", "1VAR", NULL};
	//unset_builtin(shell, args1);
	ft_printf(1, "exit_status: %d\n", shell->exit_status);
	char *args2[] = {"export", NULL};
	export_builtin(shell, args2);
	ft_printf(1, "exit_status: %d\n", shell->exit_status);
	env_builtin(shell);
	ft_printf(1, "exit_status: %d\n", shell->exit_status);
	while (1)
	{
		shell->cmd = readline("minishell$ ");
		check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), \
			shell->cmd, "Read line failed");
		if (shell->cmd[0] != '\0')
		{
			add_history(shell->cmd);
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
			//handle_input(shell->cmd);
			//free(shell->cmd);
			ft_lstremove_mem_node(&(shell->mem_allocation.ptr_mem_list), shell->cmd);
		}
	}
	free_exit_error(shell, 0, "teste");
 	return (0);
}*/