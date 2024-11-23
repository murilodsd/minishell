#include "../../includes/minishell.h"

int	handle_s_quotes(char *cmd, int i, t_shell *shell)
{
	int		j;
	char	*tmp;

	j = i + 1;
	while (cmd[j])
	{
		if (cmd[j] == '\'')
			break ;
		j++;
	}
	tmp = ft_substr(cmd, i + 1, j - i - 1);
//	check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), tmp,
//		"Substr malloc failed");
	take_out_quotes(&tmp, SINGLE);
	add_token(&shell, tmp, WORD, SINGLE);
	return (j);
}

int	handle_d_quotes(char *cmd, int i, t_shell *shell)
{
	int		j;
	char	*tmp;

	j = i + 1;
	j = ignore_quotes(cmd, j);
	while (cmd[j])
	{
		if (cmd[j] == '\"')
			break ;
		j++;
	}
	tmp = ft_substr(cmd, i + 1, j - i - 1);
//	check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), tmp,
//		"Substr malloc failed");
	take_out_quotes(&tmp, DOUBLE);
	add_token(&shell, tmp, WORD, DOUBLE);
	return (j);
}

int	handle_pipe(char *cmd, int i, t_shell *shell)
{
	char	*tmp;

	tmp = ft_substr(cmd, i, 1);
//	check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), tmp,
//		"Substr malloc failed");
	add_token(&shell, tmp, PIPE, NO_QUOTE);
	return (i);
}

int	handle_env_var(char *cmd, int i, t_shell *shell)
{
	char	*tmp;

	if (cmd[i + 1] == '?')
	{
		tmp = ft_substr(cmd, i, 2);
//		check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), tmp,
//			"Substr malloc failed");
		add_token(&shell, tmp, ENV_VAR_EXIT_CODE, NO_QUOTE);
		return (i + 1);
	}
	else
		tmp = ft_substr(cmd, i, 1);
//	check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), tmp,
//		"Substr malloc failed");
	if (cmd[i + 1] == '\0' || ft_isspace(cmd[i + 1]))
		add_token(&shell, tmp, WORD, NO_QUOTE);
	else
		add_token(&shell, tmp, ENV_VAR, NO_QUOTE);
	return (i);
}

int	handle_space(char *cmd, int i, t_shell *shell)
{
	char	*tmp;

	i = ignore_spaces(cmd, i);
	tmp = ft_strdup(" ");
//	check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), tmp,
//		"Substr malloc failed");
	add_token(&shell, tmp, SPACE_TOKEN, NO_QUOTE);
	return (i - 1);
}
