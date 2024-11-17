#include "../../includes/minishell.h"

void	handle_input(char *cmd, t_shell *shell)
{
	(void)shell;
	if (ft_strncmp(cmd, "exit", 4) == 0)
		exit(0);
	if (syntax_check(cmd))
		return ;
	tokenizer(cmd, shell);
	parser();
	binary_tree();
	builtins();
	executer();
	handle_error();
}
