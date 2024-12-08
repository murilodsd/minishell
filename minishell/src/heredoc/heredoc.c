/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:30:21 by dramos-j          #+#    #+#             */
/*   Updated: 2024/12/08 11:15:05 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	save_heredoc_info(t_shell *shell)
{
	t_token		*tmp;
	t_heredoc	*tmp_hd;

	tmp = shell->token;
	while (tmp)
	{
		if (tmp->type == HEREDOC)
		{
			tmp_hd = shell->heredoc;
			if (tmp_hd->i == 0)
			{
				tmp_hd->i = 1;
				tmp_hd->eof = ft_strdup(tmp->next->data);
				tmp_hd->eof_quote = tmp->next->quote;
			}
			else
				assign_heredoc(&tmp_hd, tmp->next->data, tmp->next->quote);
		}
		tmp = tmp->next;
	}
}

void	fill_fd_heredoc(t_heredoc *tmp_hd, t_shell *shell)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (!line)
		{
			printf("minishell: warning: here-document delimited" \
				" by end-of-file (wanted `%s')\n", tmp_hd->eof);
			break ;
		}
		if (ft_strncmp(line, tmp_hd->eof, ft_strlen(tmp_hd->eof)) == 0)
		{
			free(line);
			break ;
		}
		if (tmp_hd->eof_quote == NO_QUOTE)
			check_hd_expand(&line, shell);
		write(tmp_hd->fd_heredoc, line, ft_strlen(line));
		write(tmp_hd->fd_heredoc, "\n", 1);
		free(line);
	}
}

void	handle_heredoc_child(t_heredoc *tmp_hd, t_shell *shell)
{
	reset_sig_int_ignore_sig_quit();
	fill_fd_heredoc(tmp_hd, shell);
	close(tmp_hd->fd_heredoc);
	exit(0);
}

void	heredoc(t_shell *shell)
{
	t_heredoc	*tmp_hd;
	char		*i;
	int			status;
	pid_t		pid;

	ignore_sig_int_and_quit();
	save_heredoc_info(shell);
	tmp_hd = shell->heredoc;
	while (tmp_hd)
	{
		i = ft_itoa(tmp_hd->i);
		tmp_hd->fd_heredoc_path = ft_strjoin("/tmp/tmp_heredoc", i);
		free(i);
		tmp_hd->fd_heredoc = \
			open(tmp_hd->fd_heredoc_path, O_CREAT | O_RDWR | O_TRUNC, 0644);
		pid = fork();
		if (pid == 0)
			handle_heredoc_child(tmp_hd, shell);
		waitpid(pid, &status, 0);
		if (get_child_status(status) == 130)
		{
			handle_ctrl_c_hd(shell);
			return ;
		}
		close(tmp_hd->fd_heredoc);
		tmp_hd = tmp_hd->next;
	}
	include_hd_path(shell);
	handle_signals();
}
