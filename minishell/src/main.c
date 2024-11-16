/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:09:36 by mde-souz          #+#    #+#             */
/*   Updated: 2024/11/16 19:45:50 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_signal;

int	main(int argc, char **argv, char **envp)
{
	t_shell		*shell;
	//REVIEW -> APAGAR LINHA DEBAIXO
	char *args[] = {"export", "1var", "var2=", "var3=50", "var-=50", "var4", NULL};
	init_data(&shell, argc, argv, envp);
	export_builtin(shell, args);
	char *args2[] = {"export", NULL};
	export_builtin(shell, args2);
	env_builtin(shell->envp_lst);
/* 	while (1)
	{
		shell->cmd = readline("minishell$ ");
		check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), \
			shell->cmd, "Read line failed");
		if (shell->cmd[0] != '\0')
		{
			add_history(shell->cmd);
			handle_input(shell->cmd);
			free(shell->cmd);
		}
	} */
	free_exit_error(shell,0,"teste");
	return (0);
}