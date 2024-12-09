/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:42:20 by mde-souz          #+#    #+#             */
/*   Updated: 2024/12/09 13:43:31 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	calculate_total_vars(t_list *envp)
{
	int	total;

	total = 0;
	while (envp)
	{
		if (((t_var *)(envp->content))->value)
			total++;
		envp = envp->next;
	}
	return (total);
}

size_t	total_length(t_list *envp)
{
	size_t	size;

	size = ft_strlen(((t_var *)(envp->content))->name);
	size += ft_strlen(((t_var *)(envp->content))->value);
	return (size);
}

char	**get_exported_env_vars(t_shell *shell, t_list *envp)
{
	char	**envp_copy;
	int		i;

	if (!envp)
		return (NULL);
	envp_copy = ft_calloc(calculate_total_vars(envp) + 1, sizeof(char *));
	check_mem_alloc(shell, &(shell->mem_allocation.matrix_mem_list), \
		envp_copy, "Calloc failed");
	i = -1;
	while (envp)
	{
		if (((t_var *)(envp->content))->value)
		{
			envp_copy[++i] = ft_calloc(total_length(envp) + 2, sizeof(char));
			if (!envp_copy[i])
				free_exit_error(shell, GENERAL_ERROR, "Calloc failed");
			ft_strcat(envp_copy[i], ((t_var *)(envp->content))->name);
			ft_strcat(envp_copy[i], "=");
			ft_strcat(envp_copy[i], ((t_var *)(envp->content))->value);
		}
		envp = envp->next;
	}
	return (envp_copy);
}
