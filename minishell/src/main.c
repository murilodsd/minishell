/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:09:36 by mde-souz          #+#    #+#             */
/*   Updated: 2024/11/20 18:40:22 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_signal;

int	main(int argc, char **argv, char **envp)
{
	t_shell		*shell;

	init_data(&shell, argc, argv, envp);
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
