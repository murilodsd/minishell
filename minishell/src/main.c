/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:09:36 by mde-souz          #+#    #+#             */
/*   Updated: 2024/11/20 17:44:46 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_signal;

void	create_env_lst(t_shell *shell, char **envp);
void	env_builtin(t_list *env_lst);

int	main(int argc, char **argv, char **envp)
{
	t_shell		*shell;

	init_data(&shell, argc, argv, envp);
	env_builtin(envp);
	while (1)
	{
		shell->cmd = readline("minishell$ ");
		if (shell->cmd[0] != '\0')
		{
			add_history(shell->cmd);
			handle_input(shell->cmd, shell);
			if (shell->cmd)
				free(shell->cmd);
		}
	}
	return (0);
}
