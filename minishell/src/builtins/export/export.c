#include "../../../includes/minishell.h"

void	lstadd_name_ordered(t_list **lst, t_list *new)
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
		while (node_ref->next && ft_strcmp(((t_var *)((*lst)->content))->name, ((t_var *)((new)->content))->name ) > 0)
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

/* void	add_export(t_list *export_lst, char *var)
{
	//export var=    -> var=""
	//export var=1 var2=2 var=3    -> salva todas
	//export var 1   -> bash: export: `1': not a valid identifier     (so pode comecar com letra ou _ e no nome so pode conter letras numeros e _)
} */

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
	char	*content;
	bool	find_equal_signal;

	find_equal_signal = FALSE;
	content = (char *)envp;
	if (!content)
		return ;
	ft_printf(STDOUT_FILENO, "declare -x ");
	while (*content)
	{
		ft_putchar_fd(*content, STDOUT_FILENO);
		if (*content == '=')
		{
			ft_putchar_fd('"', STDOUT_FILENO);
			find_equal_signal = TRUE;
			break;
		}
		content++;
	}
	ft_printf(STDOUT_FILENO, content);
	if (find_equal_signal == TRUE)
		ft_putchar_fd('"', STDOUT_FILENO);
	printf("%s\n", content);
}

void	export_builtin(char **export_args, t_list *export_lst)
{
	if (!export_args[1])
		ft_lstiter(export_lst, print_export);

}

