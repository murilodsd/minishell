/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:14:11 by dramos-j          #+#    #+#             */
/*   Updated: 2024/11/29 15:14:51 by mde-souz         ###   ########.fr       */
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
void		clear_list(t_token **token);

// tokenizer_utils.c
void		take_out_quotes(char **data, t_token_quote quote);
void		add_quote_token(char quote, char *cmd, int i, t_shell *shell);

#endif
