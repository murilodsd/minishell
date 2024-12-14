/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 08:09:39 by mde-souz          #+#    #+#             */
/*   Updated: 2024/12/14 16:55:46 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	edit_var(t_shell *shell, t_var *var)
{
	char	**var_value;

	if (!(var->value))
		return ;
	var_value = &((t_var *) \
		(ft_lstfind_name(shell->export_lst, var->name)->content))->value;
	if (!var->is_incremental || (var->is_incremental && !*var_value))
	{
		if (*var_value)
			ft_lstremove_mem_node(&(shell->mem_allocation.ptr_mem_list), \
				*var_value);
		*var_value = ft_strdup(var->value);
	}
	else
		*var_value = ft_strjoin(*var_value, var->value);
	check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), \
			*var_value, "Calloc failed");
}

void	add_var(t_shell *shell, t_var *var)
{
	t_list	*new_node;

	new_node = ft_lstnew(var);
	check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), \
		new_node, "Calloc failed");
	ft_lstadd_back(&(shell->envp_lst), new_node);
	new_node = ft_lstnew(var);
	check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), \
		new_node, "Calloc failed");
	ft_lstadd_var_ordered(&(shell->export_lst), new_node);
}

t_list	*ft_lstfind_name(t_list *lst, char *name)
{
	t_var	*var;

	while (lst)
	{
		var = (t_var *)lst->content;
		if (ft_strcmp(var->name, name) == 0)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

static bool	validate_var_name(char *string)
{
	int	i;

	if (!ft_isalpha(string[0]) && string[0] != '_')
		return (FALSE);
	i = 0;
	while (string[i] && \
		(string[i] != '=' && !(string[i] == '+' && string[i + 1] == '=')))
	{
		if (!ft_isalnum(string[i]) && string[i] != '_')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	get_new_var_name_and_value(t_shell *shell, t_var *var, char *string)
{
	if (!validate_var_name(string))
	{
		msg_error(NOT_VALID_IDENTIFIER, "export", string);
		shell->exit_status = EXIT_FAILURE;
		return ;
	}
	if (!ft_strchr(string, '='))
		var->name = ft_strdup(string);
	else
	{
		var->value = ft_strdup((ft_strchr(string, '=')) + 1);
		check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), \
			var->value, "Calloc failed");
		if (ft_strchr(string, '+') && \
			(ft_strchr(string, '=') > ft_strchr(string, '+')))
		{
			var->is_incremental = TRUE;
			var->name = ft_substr(string, 0, \
				ft_strchr(string, '=') - string - 1);
		}
		else
			var->name = ft_substr(string, 0, ft_strchr(string, '=') - string);
	}
	check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), \
			var->name, "Calloc failed");
}
