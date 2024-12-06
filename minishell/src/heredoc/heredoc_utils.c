/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:30:14 by dramos-j          #+#    #+#             */
/*   Updated: 2024/12/06 13:40:01 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_heredoc(t_shell *shell)
{
	shell->heredoc = ft_calloc(1, sizeof(t_heredoc));
	if (check_malloc(shell->heredoc))
		return ;
	shell->heredoc->i = 0;
	shell->heredoc->count_hd = 0;
	shell->heredoc->fd_heredoc_path = NULL;
	shell->heredoc->eof = NULL;
	shell->heredoc->eof_quote = NO_QUOTE;
	shell->heredoc->next = NULL;
}

void	clear_heredoc_list(t_shell *shell)
{
	t_heredoc	*tmp_heredoc;

	while (shell->heredoc)
	{
		tmp_heredoc = shell->heredoc;
		shell->heredoc = shell->heredoc->next;
		if (tmp_heredoc->fd_heredoc_path)
		{
			unlink(tmp_heredoc->fd_heredoc_path);
			free(tmp_heredoc->fd_heredoc_path);
		}
		if (tmp_heredoc->eof)
			free(tmp_heredoc->eof);
		if (tmp_heredoc)
			free(tmp_heredoc);
	}
}

void	assign_heredoc(t_heredoc **heredoc, char *eof, t_token_quote quote)
{
	t_heredoc	*tmp_hd;

	tmp_hd = *heredoc;
	while (tmp_hd->next)
		tmp_hd = tmp_hd->next;
	tmp_hd->next = ft_calloc(1, sizeof(t_heredoc));
	if (check_malloc(tmp_hd->next))
		return ;
	tmp_hd->next->i = tmp_hd->i + 1;
	tmp_hd->next->eof = ft_strdup(eof);
	tmp_hd->next->eof_quote = quote;
	tmp_hd->next->count_hd = tmp_hd->count_hd;
	tmp_hd->next->next = NULL;
}

void	include_hd_path(t_shell *shell)
{
	t_token		*tmp;
	t_heredoc	*tmp_hd;

	tmp = shell->token;
	tmp_hd = shell->heredoc;
	while (tmp)
	{
		if (tmp->type == HEREDOC)
		{
			tmp->type = REDIR_IN;
			rm_token(&tmp->next, shell);
			find_place(&tmp, ft_strdup(tmp_hd->fd_heredoc_path), \
				tmp->quote, REDIR_IN_FILE);
			tmp_hd = tmp_hd->next;
		}
		tmp = tmp->next;
	}
}

void	check_hd_expand(char **line, t_shell *shell)
{
	char	*new_line;

	new_line = check_env_var_d_quote(shell, *line);
	free(*line);
	*line = new_line;
}
