#include "../../../includes/minishell.h"

//unset -> só retorna
//unset nonexistentvariable -> só retorna
//unset USER -> apaga USER

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

void	ft_lstremove_var(t_shell *shell, char *name)
{
	t_list	*current;
	t_list	*previous;
	t_var	*var;

	current = (shell->envp_lst);
	previous = NULL;
	while (current)
	{
		var = (t_var *)current->content;
		if (ft_strcmp(var->name, name) == 0)
		{
			if (previous)
				previous->next = current->next;
			else
				shell->envp_lst = current->next;
			ft_lstremove_mem_node(&(shell->mem_allocation.ptr_mem_list), var->name);
			ft_lstremove_mem_node(&(shell->mem_allocation.ptr_mem_list), var->value);
			ft_lstremove_mem_node(&(shell->mem_allocation.ptr_mem_list), current->content);
			ft_lstremove_mem_node(&(shell->mem_allocation.ptr_mem_list), current);
			return ;
		}
		previous = current;
      		current = current->next;
	}
	current = (shell->export_lst);
	previous = NULL;
	while (current)
	{
		var = (t_var *)current->content;
		if (ft_strcmp(var->name, name) == 0)
		{
			if (previous)
				previous->next = current->next;
			else
				shell->export_lst = current->next;
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
			ft_lstremove_var(shell, unset_args[i]);
			i++;
		}
	}
}
