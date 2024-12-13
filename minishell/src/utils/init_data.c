/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:18:35 by mde-souz          #+#    #+#             */
/*   Updated: 2024/12/12 18:57:47 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief Creates and initializes the environment and export lists.
 *
 * This function iterates through the provided environment variables (envp),
 * creates a new variable structure for each environment variable, and adds
 * it to both the environment list (envp_lst) and the export list (export_lst)
 * in the shell structure.
 *
 * @param shell A pointer to the shell structure containing the lists and 
 * memory allocation info.
 * @param envp An array of strings representing the environment variables.

 *
 * Memory allocation failures are checked and handled by the check_mem_alloc function.
 */
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
