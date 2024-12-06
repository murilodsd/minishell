/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_handlers2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:16:01 by dramos-j          #+#    #+#             */
/*   Updated: 2024/12/06 16:21:16 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	handle_redir_append(char *cmd, int i, t_shell *shell)
{
	char	*tmp;

	tmp = ft_substr(cmd, i, 2);
	if (check_malloc(tmp))
		return (0);
	add_token(&shell, tmp, REDIR_APPEND, NO_QUOTE);
	return (i + 1);
}

int	handle_heredoc(char *cmd, int i, t_shell *shell)
{
	char	*tmp;

	if (!shell->heredoc)
		init_heredoc(shell);
	tmp = ft_substr(cmd, i, 2);
	if (check_malloc(tmp))
		return (0);
	add_token(&shell, tmp, HEREDOC, NO_QUOTE);
	shell->heredoc->count_hd++;
	return (i + 1);
}

int	handle_redir_in(char *cmd, int i, t_shell *shell)
{
	char	*tmp;

	tmp = ft_substr(cmd, i, 1);
	if (check_malloc(tmp))
		return (0);
	add_token(&shell, tmp, REDIR_IN, NO_QUOTE);
	return (i);
}

int	handle_redir_out(char *cmd, int i, t_shell *shell)
{
	char	*tmp;

	tmp = ft_substr(cmd, i, 1);
	if (check_malloc(tmp))
		return (0);
	add_token(&shell, tmp, REDIR_OUT, NO_QUOTE);
	if (cmd[i + 1] == '|')
		return (i + 1);
	return (i);
}

int	handle_word(char *cmd, int i, t_shell *shell)
{
	int		j;
	char	*tmp;

	j = i;
	while (cmd[j] && ft_isword(cmd[j]))
		j++;
	if (j > i)
	{
		tmp = ft_substr(cmd, i, j - i);
		if (check_malloc(tmp))
			return (0);
		add_token(&shell, tmp, WORD, NO_QUOTE);
	}
	if (!ft_isword(cmd[j]) && j != i)
		j--;
	return (j);
}
