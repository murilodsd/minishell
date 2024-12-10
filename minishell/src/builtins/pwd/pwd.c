/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 08:23:24 by mde-souz          #+#    #+#             */
/*   Updated: 2024/12/10 14:54:24 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*safe_getcwd(char *buf, size_t size, t_shell *shell)
{
	char	*cwd;

	cwd = getcwd(buf, size);
	if (!cwd)
		errno = 0;
	else
		check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), \
			cwd, "Getcwd failed");
	return (cwd);
}

void	pwd_builtin(t_shell *shell)
{
	char	*pwd;

	pwd = safe_getcwd(NULL, 0, shell);
	if (!pwd)
	{
		shell->exit_status = EXIT_FAILURE;
		msg_error(GENERAL_ERROR,"Getcwd failed");
		return ;
	}
	ft_printf(1, "%s\n", pwd);
	ft_lstremove_mem_node(&(shell->mem_allocation.ptr_mem_list), pwd);
	shell->exit_status = EXIT_SUCCESS;
}
