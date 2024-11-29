/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_handlers2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:39:09 by dramos-j          #+#    #+#             */
/*   Updated: 2024/11/29 13:58:57 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	looking_for_cmd(t_shell *shell)
{
	t_token	*tmp;
	t_token	*tmp_next;

	tmp = shell->token;
	while (tmp)
	{
		tmp_next = tmp->next;
		if (tmp->type == WORD)
		{
			tmp->type = COMMAND;
			while (tmp_next && tmp_next->type == WORD)
			{
				tmp = tmp_next;
				tmp_next = tmp_next->next;
				tmp->type = COMMAND;
			}
			while (tmp_next && tmp_next->type != PIPE)
			{
				tmp = tmp_next;
				tmp_next = tmp_next->next;
			}
		}
		else
			tmp = tmp_next;
	}
}

void	looking_for_cmd_args(t_shell *shell)
{
	t_token	*tmp;

	tmp = shell->token;
	while (tmp)
	{
		if (tmp->type == WORD)
			tmp->type = COMMAND_ARG;
		tmp = tmp->next;
	}
}

void	rm_env_var_error(t_shell *shell)
{
	t_token	*tmp;
	t_token	*tmp_next;

	tmp = shell->token;
	while (tmp)
	{
		tmp_next = tmp->next;
		if (tmp->type == ENV_VAR_NAME)
		{
			if (tmp == shell->token)
				shell->token = tmp_next;
			rm_token(&tmp, shell);
		}
		tmp = tmp_next;
	}
}

void	listjoin(t_shell *shell)
{
	t_token	*tmp;
	t_token	*tmp_next;
	char	*new_data;

	tmp = shell->token;
	while (tmp)
	{
		tmp_next = tmp->next;
		while (tmp_next && tmp->type == tmp_next->type)
		{
			if (tmp == shell->token)
				shell->token = tmp;
			if (tmp->quote != NO_QUOTE || tmp_next->quote != NO_QUOTE)
				tmp->quote = SINGLE;
			new_data = ft_strjoin(tmp->data, tmp_next->data);
			ft_str_replace(&(tmp->data), new_data);
			free(new_data);
			rm_token(&tmp_next, shell);
			tmp_next = tmp->next;
		}
		tmp = tmp_next;
	}
}

void	rm_space_token(t_shell *shell)
{
	t_token	*tmp;
	t_token	*tmp_next;

	tmp = shell->token;
	while (tmp)
	{
		tmp_next = tmp->next;
		if (tmp->type == SPACE_TOKEN)
		{
			if (tmp == shell->token)
				shell->token = tmp_next;
			rm_token(&tmp, shell);
		}
		tmp = tmp_next;
	}
}
