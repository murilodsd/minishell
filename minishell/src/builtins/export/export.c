#include "../../../includes/minishell.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		ft_lstlast(*lst)->next = new;
	}
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	if (*lst)
		new->next = *lst;
	*lst = new;
}

void	ft_lstadd_string_ordered(t_list **lst, t_list *new)
{
	t_list	*node_ref;

	if (!lst || !new)
		return ;
	if (!(*lst))
		*lst = new;
	else if (ft_strcmp((char *)((*lst)->content), (char *)((new)->content)) > 0)
	{
		new->next = *lst;
		*lst = new;
	}
	else
	{
		node_ref = *lst;
		while (node_ref->next && (ft_strcmp((char *)(node_ref->next->content), (char *)((new)->content)) < 0))
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

void	print_export(void *envp)
{
	char	*content;

	content = (char *)envp;
	printf("%s\n", content);
}

void	export_builtin(t_list *export_lst)
{
	ft_lstiter(export_lst, print_export);
}

