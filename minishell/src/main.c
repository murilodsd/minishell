/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:09:36 by mde-souz          #+#    #+#             */
/*   Updated: 2024/11/19 10:39:45 by mde-souz         ###   ########.fr       */
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
	//char *envp1[] = {"aaa=primeira", "var2=1", "var3=", "var", NULL};
	char *args[] = {"cd", "src", NULL};
	init_data(&shell, argc, argv, envp);
	pwd_builtin();
	cd_builtin(shell, args);
	char *args0[] = {"export", NULL};
	export_builtin(shell, args0);
	char *args1[] = {"unset", "PWD", "OLDPWD", NULL};
	unset_builtin(shell, args1);
	export_builtin(shell, args0);
	env_builtin(shell->envp_lst);
	char *args2[] = {"cd", "utils", NULL};
	cd_builtin(shell, args2);
	export_builtin(shell, args0);
	env_builtin(shell->envp_lst);
	char *args3[] = {"cd", NULL};
	cd_builtin(shell, args3);
	export_builtin(shell, args0);
	env_builtin(shell->envp_lst);
	exit_builtin(shell,)
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
// 	free_exit_error(shell, 0, "teste");
// 	return (0);
}