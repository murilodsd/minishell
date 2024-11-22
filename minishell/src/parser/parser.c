#include "../../includes/minishell.h"

void	polish_list(t_shell *shell)
{
	looking_for_here_doc(shell);
	looking_for_env_var(shell);
	looking_for_redir(shell);
}

void	parser(t_shell *shell)
{
	polish_list(shell);
	print_list(shell->token);
	clear_list(&(shell->token));
}
