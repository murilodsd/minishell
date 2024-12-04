/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:30:06 by dramos-j          #+#    #+#             */
/*   Updated: 2024/12/01 17:30:07 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H
# include "minishell.h"

// heredoc.c
void	save_heredoc_info(t_shell *shell);
void	fill_fd_heredoc(t_heredoc *tmp_hd);
void	heredoc(t_shell *shell);

// heredoc_utils.c
void	init_heredoc(t_shell *shell);
void	clear_heredoc_list(t_shell *shell);
void	assign_heredoc(t_heredoc **heredoc, char *eof);

#endif
