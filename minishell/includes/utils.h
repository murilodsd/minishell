/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:19:32 by mde-souz          #+#    #+#             */
/*   Updated: 2024/12/13 14:15:58 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "minishell.h"

// handle_mem.c
void	check_mem_alloc(t_shell *shell, t_list **ptr_or_matrix_list, \
	void *ptr, char *error_msg);

//free_functions.c
void	free_exit(t_shell *shell);
void	free_exit_error(t_shell *shell, t_error_codes error_code, \
	char *error_msg);
void	free_all(t_shell *shell);
void	free_restart(t_shell *shell);
void	free_all_heredoc(t_shell *shell);

// handle_error.c
void	msg_error(t_error_codes error_code, char *error_msg, ...);
void	ft_lstremove_mem_node(t_list **lst, void *content);

// handle_input.c
void	handle_input(char *cmd, t_shell *shell);

// init_data.c
void	init_data(t_shell **shell, char **envp);

// utils.c
int		ft_isspace(char c);
int		ignore_spaces(char *cmd, int i);
int		ft_isword(char c);
int		check_malloc(void *ptr);
int		check_var_alone(t_shell *shell);

#endif
