/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:26:26 by mde-souz          #+#    #+#             */
/*   Updated: 2024/12/13 12:06:13 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ignore_spaces(char *cmd, int i)
{
	while (cmd[i] && ft_isspace(cmd[i]))
		i++;
	return (i);
}

int	ft_isword(char c)
{
	if (ft_isspace(c) || c == '\'' || c == '"'
		|| c == '|' || c == '$' || c == '>'
		|| c == '<')
		return (0);
	return (1);
}

int	check_malloc(void *ptr)
{
	if (!ptr)
	{
		printf("Malloc failed\n");
		return (1);
	}
	return (0);
}

int	check_var_alone(t_shell *shell)
{
	t_token	*token;

	token = shell->token;
	if (token->type == ENV_VAR_NAME && token->next
		&& token->next->type == NULL_TOKEN)
	{
		shell->exit_status = 0;
		free_restart(shell);
		return (1);
	}
	return (0);
}
