/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:14:11 by dramos-j          #+#    #+#             */
/*   Updated: 2024/12/01 15:36:02 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H
# include "minishell.h"

// tokenizer.c
void		tokenizer(char *cmd, t_shell *shell, int i);

// tokenizer_handlers.c
int			handle_s_quotes(char *cmd, int i, t_shell *shell);
int			handle_d_quotes(char *cmd, int i, t_shell *shell);
int			handle_pipe(char *cmd, int i, t_shell *shell);
int			handle_env_var(char *cmd, int i, t_shell *shell);
int			handle_space(char *cmd, int i, t_shell *shell);

// tokenizer_handlers2.c
int			handle_redir_append(char *cmd, int i, t_shell *shell);
int			handle_heredoc(char *cmd, int i, t_shell *shell);
int			handle_redir_in(char *cmd, int i, t_shell *shell);
int			handle_redir_out(char *cmd, int i, t_shell *shell);
int			handle_word(char *cmd, int i, t_shell *shell);

// tokenizer_handle_list.c
void		add_token(t_shell **shell, char *data, \
	enum e_token_type type, enum e_token_quote quote);
void		rm_token(t_token **token, t_shell *shell);
void		find_place(t_token *token, char *word, t_token_quote quote);
t_token		*last_token(t_token *token);
t_token		*last_token(t_token *token);
void		clear_token_list(t_shell *shell);

// tokenizer_utils.c
void		take_out_quotes(char **data, t_token_quote quote);

#endif
