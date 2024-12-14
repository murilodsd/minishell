/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:18:35 by mde-souz          #+#    #+#             */
/*   Updated: 2024/12/14 17:09:06 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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


void	init_data(t_shell **shell, char **envp)
{
	*shell = ft_calloc(sizeof(t_shell), 1);
	if (!(*shell))
	{
		msg_error(GENERAL_ERROR, "Calloc Error\n");
		exit(EXIT_FAILURE);
	}
	(*shell)->envp_lst = NULL;
	(*shell)->export_lst = NULL;
	(*shell)->exit_status = EXIT_SUCCESS;
	(*shell)->fd_in = STDIN_FILENO;
	(*shell)->fd_out = STDOUT_FILENO;
	create_env_export_lst(*shell, envp);
	handle_signals();
}
