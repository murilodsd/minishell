/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:09:36 by mde-souz          #+#    #+#             */
/*   Updated: 2024/11/20 11:15:02 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_signal;

	//export var=    -> var=""
	//export var=1 var2=2 var=3    -> salva todas
	//export var 1   -> bash: export: `1': not a valid identifier     (so pode comecar com letra ou _ e no nome so pode conter letras numeros e _)
	//export var=1; export var;     -> irá manter o valor anterior de var
	//export = ->  bash: export: `=': not a valid identifier

#define MAX_TOKENS 100

char **parse_input(char *input) {
    char **tokens = malloc(MAX_TOKENS * sizeof(char *));
    char *token;
    int i = 0;

    if (!tokens) {
        ft_printf(2, "Allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(input, " \t\r\n\a");
    while (token != NULL) {
        tokens[i] = token;
        i++;

        if (i >= MAX_TOKENS) {
            ft_printf(2, "Too many tokens\n");
            exit(EXIT_FAILURE);
        }

        token = strtok(NULL, " \t\r\n\a");
    }
    tokens[i] = NULL;
    return tokens;
}

int	main(int argc, char **argv, char **envp)
{
	t_shell		*shell;
	char **args;
	(void)envp;
	//REVIEW -> APAGAR LINHA DEBAIXO
	//char *envp1[] = {"aaa=primeira", "var2=1", "var3=", "var", NULL};
	//char *args[] = {"cd", "src", NULL};
	init_data(&shell, argc, argv, envp);
	char *args3[] = {"cd", "", NULL};
	ft_printf(1, RED"%s %c%c\n"RESET, "cd", '"','"');
	cd_builtin(shell, args3);
	pwd_builtin(shell);
	ft_printf(1, "%d\n", shell->exit_status);
	char *args4[] = {"cd", NULL};
	ft_printf(1, RED"%s\n"RESET, "cd");
	cd_builtin(shell, args4);
	pwd_builtin(shell);
	ft_printf(1, "%d\n", shell->exit_status);
	char *args5[] = {"cd", "nonexistent", NULL};
	ft_printf(1, RED"%s %s\n"RESET, "cd", "nonexistent");
	cd_builtin(shell, args5);
	pwd_builtin(shell);
	ft_printf(1, "%d\n", shell->exit_status);
	char *args6[] = {"cd", "..", NULL};
	ft_printf(1, RED"%s %s\n"RESET, "cd", "..");
	cd_builtin(shell, args6);
	pwd_builtin(shell);
	ft_printf(1, "%d\n", shell->exit_status);
	char *args7[] = {"unset", "HOME", NULL};
	unset_builtin(shell, args7);
	char *args8[] = {"cd", NULL};
	ft_printf(1, RED"%s\n"RESET, "cd");
	cd_builtin(shell, args8);
	pwd_builtin(shell);
	ft_printf(1, "%d\n", shell->exit_status);
	char *args9[] = {"cd", "um", "dois", NULL};
	ft_printf(1, RED"%s %s %s\n"RESET, "cd", "um", "dois");
	cd_builtin(shell, args9);
	pwd_builtin(shell);
	ft_printf(1, "%d\n", shell->exit_status);
	// char *args10[] = {"exit", "9223372036854775808", NULL};
	// exit_builtin(shell, args10);
	while (1)
	{
		shell->cmd = readline("minishell$ ");
		check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), \
			shell->cmd, "Read line failed");
		if (shell->cmd[0] != '\0')
		{
			args = parse_input(shell->cmd);
			check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), \
			args, "Read line failed");
			if (!ft_strcmp(args[0], "cd"))
				cd_builtin(shell, args);
			else if (!ft_strcmp(args[0], "exit"))
				exit_builtin(shell, args);
			ft_printf(1, "exit_status: %d\n", shell->exit_status);
			pwd_builtin(shell);
			add_history(shell->cmd);
			//handle_input(shell->cmd);
			//free(shell->cmd);
			ft_lstremove_mem_node(&(shell->mem_allocation.ptr_mem_list), shell->cmd);
		}
	}
	free_exit_error(shell, 0, "teste");
 	return (0);
}