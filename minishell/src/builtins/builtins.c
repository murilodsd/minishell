#include "../../includes/minishell.h"

void	builtins(t_shell *shell, char **args)
{
	if (!ft_strcmp(args, "pwd"))
		pwd_builtin(shell);
	if (!ft_strcmp(args, "echo"))
		echo_builtin(shell, args);
	if (!ft_strcmp(args, "cd"))
		cd_builtin(shell, args);
	if (!ft_strcmp(args, "export"))
		export_builtin(shell, args);
	if (!ft_strcmp(args, "unset"))
		unset_builtin(shell, args);
	if (!ft_strcmp(args, "env"))
		env_builtin(shell);
	if (!ft_strcmp(args, "exit"))
		exit_builtin(shell, args);
	else
		//exec
		ft_printf(1, "exec");
}
