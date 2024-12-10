/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 08:23:24 by mde-souz          #+#    #+#             */
/*   Updated: 2024/12/09 08:23:27 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*safe_getcwd(char *buf, size_t size, t_shell *shell)
{
	char	*cwd;

	cwd = getcwd(buf, size);
	check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), \
		cwd, "Getcwd failed");
	return (cwd);
}

void	pwd_builtin(t_shell *shell)
{
	char	*pwd;

	pwd = safe_getcwd(NULL, 0, shell);
	ft_printf(1, "%s\n", pwd);
	ft_lstremove_mem_node(&(shell->mem_allocation.ptr_mem_list), pwd);
	shell->exit_status = EXIT_SUCCESS;
}
