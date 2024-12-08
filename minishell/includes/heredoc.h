/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:30:06 by dramos-j          #+#    #+#             */
/*   Updated: 2024/12/08 14:44:35 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H
# include "minishell.h"

// heredoc.c
void	save_heredoc_info(t_shell *shell);
int		fill_fd_heredoc(t_heredoc *tmp_hd, t_shell *shell);
void	heredoc(t_shell *shell);

// heredoc_utils.c
void	init_heredoc(t_shell *shell);
void	clear_heredoc_list(t_shell *shell, int in_heredoc);
void	assign_heredoc(t_heredoc **heredoc, char *eof, t_token_quote quote);
void	include_hd_path(t_shell *shell);
void	check_hd_expand(char **line, t_shell *shell);

#endif
