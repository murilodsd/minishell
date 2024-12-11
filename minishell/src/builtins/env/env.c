/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 09:30:45 by mde-souz          #+#    #+#             */
/*   Updated: 2024/12/10 21:23:06 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	print_env(void *envp)
{
	t_var	*content;

	if (!envp)
		return ;
	content = (t_var *)envp;
	if (content->value)
		printf("%s=%s\n", content->name, content->value);
}

void	env_builtin(t_shell *shell, char **args, bool is_root)
{
	if (args[1])
	{
		shell->exit_status = EXIT_CMD_NOT_FOUND;
		ft_printf(STDERR_FILENO, "env: '%s': No such file or directory\n", \
			args[1]);
		if (!is_root)
			free_exit(shell);
		else
			return ;
	}
	ft_lstiter(shell->envp_lst, print_env);
	shell->exit_status = EXIT_SUCCESS;
}
