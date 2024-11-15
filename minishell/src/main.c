/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:09:36 by mde-souz          #+#    #+#             */
/*   Updated: 2024/11/15 12:19:37 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_signal;

int	main(int argc, char **argv, char **envp)
{
	t_shell		*shell;

	init_data(&shell, argc, argv, envp);
	env_builtin(shell->envp_lst);
	export_builtin(shell->export_lst);
	while (1)
	{
		shell->cmd = readline("minishell$ ");
		check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), \
			shell->cmd, "Read line failed");
		if (shell->cmd[0] != '\0')
		{
			add_history(shell->cmd);
			handle_input(shell->cmd, shell);
			free(shell->cmd);
		}
	}
	return (0);
}
