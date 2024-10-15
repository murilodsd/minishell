/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:23:31 by dramos-j          #+#    #+#             */
/*   Updated: 2024/10/15 15:34:03 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_input(char *cmd)
{
	if (ft_strncmp(cmd, "exit", 4) == 0)
		exit(0);
	else
		printf("minishell: command not found: %s\n", cmd);
}
