/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:20:02 by mde-souz          #+#    #+#             */
/*   Updated: 2024/12/14 17:08:42 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_exit(t_shell *shell)
{
	int	exit_status;

	exit_status = shell->exit_status;
	free_all(shell);
	exit(exit_status);
}

void	free_exit_error(t_shell *shell, t_error_codes error_code, \
	char *error_msg)
{
	if (!shell->exit_status)
		shell->exit_status = 1;
	if (error_msg)
		msg_error(error_code, error_msg);
	free_exit(shell);
}

void	free_restart(t_shell *shell)
{
	if (shell->token)
		clear_token_list(shell);
	if (shell->heredoc)
		clear_heredoc_list(shell);
}

void	free_all_heredoc(t_shell *shell)
{
	if (shell->fd_out != -1)
		close(shell->fd_out);
	if (shell->fd_in != -1)
		close(shell->fd_in);
	if (shell->token)
		clear_token_list(shell);
	if (shell->mem_allocation.ptr_mem_list != NULL)
		ft_lstclear(&(shell->mem_allocation.ptr_mem_list), free);
	if (shell->mem_allocation.matrix_mem_list != NULL)
		ft_lstclear(&(shell->mem_allocation.matrix_mem_list), ft_free_matrix);
	if (shell->token)
		clear_token_list(shell);
	if (shell->heredoc)
		clear_heredoc_list(shell);
	free(shell);
}

void	free_all(t_shell *shell)
{
	if (shell->fd_out != -1)
		close(shell->fd_out);
	if (shell->fd_in != -1)
		close(shell->fd_in);
	if (shell->token)
		clear_token_list(shell);
	if (shell->mem_allocation.ptr_mem_list != NULL)
		ft_lstclear(&(shell->mem_allocation.ptr_mem_list), free);
	if (shell->mem_allocation.matrix_mem_list != NULL)
		ft_lstclear(&(shell->mem_allocation.matrix_mem_list), ft_free_matrix);
	if (shell->token)
		clear_token_list(shell);
	if (shell->heredoc)
		clear_heredoc_list(shell);
	free(shell);
}
