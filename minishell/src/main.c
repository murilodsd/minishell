/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:09:36 by mde-souz          #+#    #+#             */
/*   Updated: 2024/11/17 21:18:32 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_signal;

	//export var=    -> var=""
	//export var=1 var2=2 var=3    -> salva todas
	//export var 1   -> bash: export: `1': not a valid identifier     (so pode comecar com letra ou _ e no nome so pode conter letras numeros e _)
	//export var=1; export var;     -> irá manter o valor anterior de var
	//export = ->  bash: export: `=': not a valid identifier

int	main(int argc, char **argv, char **envp)
{
	t_shell		*shell;
	(void)envp;
	//REVIEW -> APAGAR LINHA DEBAIXO
	char *envp1[] = {"aaa=primeira", "var2=1", "var3=", "var", NULL};
	char *args[] = {"export", "", "1var=", "var2 =", "var2=2", "var3", "var=", "var4", NULL};
	init_data(&shell, argc, argv, envp1);
	export_builtin(shell, args);
	char *args0[] = {"export", NULL};
	export_builtin(shell, args0);
	char *args1[] = {"unset", "aaa", "v1var", "var3", "1VAR", "", NULL};
	unset_builtin(shell, args1);
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
	free_exit_error(shell, 0, "teste");
	return (0);
}