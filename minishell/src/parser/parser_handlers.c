/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:00:21 by dramos-j          #+#    #+#             */
/*   Updated: 2024/12/06 16:19:32 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	looking_for_here_doc(t_shell *shell)
{
	t_token	*tmp;

	tmp = shell->token;
	while (tmp)
	{
		if (tmp->type == HEREDOC)
		{
			tmp = tmp->next;
			while (tmp->type == SPACE_TOKEN)
				tmp = tmp->next;
			tmp->type = EOF_TOKEN;
			while (tmp->next && (tmp->next->type == WORD
					|| tmp->next->type == ENV_VAR_NAME
					|| tmp->next->type == ENV_VAR
					|| tmp->next->type == ENV_VAR_EXIT_CODE))
			{
				tmp = tmp->next;
				tmp->type = EOF_TOKEN;
			}
		}
		tmp = tmp->next;
	}
}

void	looking_for_env_var(t_shell *shell)
{
	t_token	*tmp;
	t_token	*tmp_next;

	tmp = shell->token;
	while (tmp)
	{
		tmp_next = tmp->next;
		if (tmp->type == ENV_VAR && tmp_next && tmp_next->quote == NO_QUOTE)
		{
			if (tmp == shell->token)
				shell->token = tmp_next;
			rm_token(&tmp, shell);
			tmp = tmp_next;
			tmp_next = tmp->next;
			check_env_var(tmp, shell);
		}
		else if (tmp->type == ENV_VAR_EXIT_CODE)
			check_exit_code(tmp, shell);
		tmp = tmp_next;
	}
}

void	looking_d_quote(t_shell *shell)
{
	t_token	*tmp;
	char	*new_data;

	tmp = shell->token;
	while (tmp)
	{
		if (tmp->quote == DOUBLE && tmp->type != EOF_TOKEN && tmp->data)
		{
			new_data = check_env_var_d_quote(shell, tmp->data);
			if (new_data && ft_strcmp(tmp->data, new_data) != 0)
				ft_str_replace(&(tmp->data), new_data);
			if (new_data)
				free(new_data);
		}
		tmp = tmp->next;
	}
}

void	looking_for_redir(t_shell *shell)
{
	t_token	*tmp;

	tmp = shell->token;
	while (tmp)
	{
		if (tmp->type == REDIR_IN)
			tmp = find_redir_file(tmp, REDIR_IN_FILE);
		else if (tmp->type == REDIR_OUT)
			tmp = find_redir_file(tmp, REDIR_OUT_FILE);
		else if (tmp->type == REDIR_APPEND)
			tmp = find_redir_file(tmp, REDIR_APPEND_FILE);
		else
			tmp = tmp->next;
	}
}
