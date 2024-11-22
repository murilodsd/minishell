#ifndef PARSER_H
# define PARSER_H
# include "minishell.h"

//parser.c

void	polish_list(t_shell *shell);
void	parser(t_shell *shell);

//parser_handlers.c
void	looking_for_here_doc(t_shell *shell);
void	looking_for_env_var(t_shell *shell);
void	looking_for_redir(t_shell *shell);
void	looking_d_quote(t_shell *shell);

//parser_checkers.c
void	check_env_var(t_token *token, t_shell *shell);
void	check_exit_code(t_token *token, t_shell *shell);

//parser_utils.c
void	expand_var(t_token *token, t_shell *shell);
void	split_token(t_token *token, int i);
void	expand_var_d_quote(t_token *token, int i);
char	*ft_getenv(t_list *envp_lst, char *name);

// apagar.c
void		clear_list(t_token **token);
char		*format_data_parentheses(const char *data);
const char	*get_token_type_str(t_token_type type);
const char	*get_token_quote_str(t_token_quote quote);
void		print_list(t_token *token);

#endif
