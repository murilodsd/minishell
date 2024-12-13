/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:55:27 by dramos-j          #+#    #+#             */
/*   Updated: 2024/12/13 12:06:24 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handle_input(char *cmd, t_shell *shell)
{
	void	*tree;

	if (syntax_check(cmd) == 1)
	{
		shell->exit_status = EXIT_USAGE_SYNTAX_ERROR;
		return ;
	}
	else if (syntax_check(cmd) == 2)
		return ;
	tokenizer(cmd, shell, 0);
	parser(shell);
	if (!shell->token)
		return ;
	tree = build_tree(shell, shell->token);
	executer(shell, tree);
	handle_signals();
	free_restart(shell);
}
