#include "../../includes/minishell.h"

void	polish_list(t_shell *shell)
{
	looking_for_here_doc(shell);
	looking_for_env_var(shell);
	looking_d_quote(shell);
	looking_for_redir(shell);
}

void	parser(t_shell *shell)
{
	char	*char_null;

	char_null = ft_strdup("");
	polish_list(shell);
	add_token(&shell, char_null, NULL_TOKEN, NO_QUOTE);
	print_list(shell->token);
	clear_list(&(shell->token));
}
