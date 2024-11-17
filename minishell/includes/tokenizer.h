#ifndef TOKENIZER_H
# define TOKENIZER_H
# include "minishell.h"

// tokenizer.c
void	tokenizer(char *cmd, t_shell *shell);

// tokenizer_handlers.c
int		handle_s_quotes(char *cmd, int i, t_shell *shell);
int		handle_d_quotes(char *cmd, int i, t_shell *shell);
int		handle_pipe(char *cmd, int i, t_shell *shell);
int		handle_env_var(char *cmd, int i, t_shell *shell);

// tokenizer_handlers2.c
int		handle_redir_append(char *cmd, int i, t_shell *shell);
int		handle_heredoc(char *cmd, int i, t_shell *shell);
int		handle_redir_in(char *cmd, int i, t_shell *shell);
int		handle_redir_out(char *cmd, int i, t_shell *shell);
int		handle_word(char *cmd, int i, t_shell *shell);

// tokenizer_handle_list.c
void	init_token(t_shell **shell);
void	add_token(t_shell **shell, char *data, enum e_token_type type, enum e_token_quote quote);

// tokenizer_utils.c
int		ft_isword(char c);


// apagar depois
char	*format_data_parentheses(const char *data);
const char	*get_token_type_str(t_token_type type);
const char	*get_token_quote_str(t_token_quote quote);
void	print_list(t_token *token);
void	clear_list(t_token **token);

#endif
