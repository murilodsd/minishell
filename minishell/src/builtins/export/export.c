#include "../../../includes/minishell.h"

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
		edit_var(shell, shell->export_lst, var);
	else
		add_var(shell, shell->export_lst, var);
	if (ft_lstfind_name(shell->envp_lst, var->name))
		edit_var(shell, shell->envp_lst, var);
	else if ((var->value))
		add_var(shell, shell->envp_lst, var);
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

