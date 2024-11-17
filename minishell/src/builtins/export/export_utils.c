#include "../../../includes/minishell.h"

void	edit_var(t_shell *shell, t_list *lst, t_var *var)
{
	char	**var_value;


	if (!(var->value))
		return ;
	var_value = &((t_var *)\
		(ft_lstfind_name(lst, var->name)->content))->value;
	ft_lstremove_mem_node(&(shell->mem_allocation.ptr_mem_list), *var_value);
	*var_value = ft_strdup(var->value);
	check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), \
			*var_value, "Calloc failed");
}

void	add_var(t_shell *shell, t_list *lst, t_var *var)
{
	t_list	*new_node;

	if (lst == shell->envp_lst)
	{
		new_node = ft_lstnew(var);
		check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), \
			new_node, "Calloc failed");
		ft_lstadd_back(&(shell->envp_lst), new_node);
	}
	else
	{
		new_node = ft_lstnew(var);
		check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), \
			new_node, "Calloc failed");
		ft_lstadd_var_ordered(&(shell->export_lst), new_node);
	}
}

t_list	*ft_lstfind_name(t_list *lst, char *name)
{
	t_var *var;

	while (lst)
	{
		var = (t_var *)lst->content;
		if (ft_strcmp(var->name, name) == 0)
			return lst;
		lst = lst->next;
	}
	return NULL;
}

static bool	validate_var_name(char *string)
{
	int	i;

	if (!ft_isalpha(string[0]) && string[0] != '_')
		return (FALSE);
	i = 0;
	while (string[i] && string[i] != '=')
	{
		if (!ft_isalnum(string[i]) && string[i] != '_')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	get_var_name_and_value(t_shell *shell, t_var *var, char *string)
{
		if (!validate_var_name(string))
		{
			msg_error(NOT_VALID_IDENTIFIER, "export", string);
			shell->exit_status = EXIT_FAILURE;
			return ;
		}
		if (!strchr(string, '='))
			var->name = string;
		else
		{
			var->value = ft_strdup((ft_strchr(string, '=')) + 1);
			check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), \
				var->value, "Calloc failed");
			var->name = ft_substr(string, 0, ft_strchr(string, '=') - string);
			check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), \
				var->name, "Calloc failed");
		}
}