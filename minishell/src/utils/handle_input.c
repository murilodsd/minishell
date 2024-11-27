#include "../../includes/minishell.h"

void	handle_input(char *cmd, t_shell *shell)
{
	if (ft_strncmp(cmd, "exit", 4) == 0)
	{
		free_exit_error(shell, EXIT_SUCCESS, NULL);
		exit(0);
	}
	if (syntax_check(cmd))
		return ;
	tokenizer(cmd, shell, 0);
	parser(shell);
	binary_tree(shell);
	builtins();
	executer();
	handle_error();
	clear_list(&(shell->token));
}
