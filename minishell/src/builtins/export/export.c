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

void	add_export(t_shell *shell, char *export_arg)
{
	//export var=    -> var=""
	//export var=1 var2=2 var=3    -> salva todas
	//export var 1   -> bash: export: `1': not a valid identifier     (so pode comecar com letra ou _ e no nome so pode conter letras numeros e _)
	//export var=1; export var;     -> irá manter o valor anterior de var
	//export = ->  bash: export: `=': not a valid identifier
	t_var	*var;

	var = (t_var *)ft_calloc(sizeof(t_var), 1);
	check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), \
			var, "Calloc failed");
	get_var_name_and_value(shell, var, export_arg);
	if (!(var->name))
		return ;
	if (ft_lstfind_name(shell->export_lst, var->name))
		edit_var(shell, var);
	else
		add_var(shell, var);
}

/* char	*put_double_quote(char *s)
{
	int		i;
	int	mem_for_double_quotes;
	char	*p;

	mem_for_double_quotes = 0;
	if (ft_strchr(s, '\n'))
		mem_for_double_quotes = 2;
	p = (char *)malloc(sizeof(char) * (ft_strlen(s) + mem_for_double_quotes + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
		int	count;

	count = 0;
	
} */

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
			add_export(shell, export_args[i]);
			i++;
		}
	}
}

