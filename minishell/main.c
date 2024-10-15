/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:38:59 by dramos-j          #+#    #+#             */
/*   Updated: 2024/10/15 16:43:35 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
	char *cmd;
	t_data data;

	data.envp = envp;
	while (1)
	{
		cmd = readline("minishell$ ");
		if (!cmd)
			exit(0);
		if (cmd)
		{
			add_history(cmd);
			handle_input(cmd);
		}
		free(cmd);
	}
	return (0);
}
