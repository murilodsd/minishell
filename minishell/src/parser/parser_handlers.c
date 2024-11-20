#include "../../includes/minishell.h"

void	looking_for_here_doc(t_shell *shell)
{
	t_token	*tmp;

	tmp = shell->token;
	while (tmp)
	{
		if (tmp->type == HEREDOC)
		{
			tmp = tmp->next;
			tmp->type = EOF_TOKEN;
		}
		tmp = tmp->next;
	}
}

void	looking_for_env_var(t_shell *shell)
{
	t_token	*tmp;

	tmp = shell->token;
	while (tmp)
	{
		if (tmp->type == ENV_VAR)
		{
			tmp = tmp->next;
			check_env_var(tmp);
		}
		tmp = tmp->next;
	}
}

void	looking_for_redir(t_shell *shell)
{
	t_token	*tmp;

	tmp = shell->token;
	while (tmp)
	{
		if (tmp->type == REDIR_IN)
		{
			tmp = tmp->next;
			tmp->type = REDIR_IN_FILE;
		}
		else if (tmp->type == REDIR_OUT)
		{
			tmp = tmp->next;
			tmp->type = REDIR_OUT_FILE;
		}
		else if (tmp->type == REDIR_APPEND)
		{
			tmp = tmp->next;
			tmp->type = REDIR_APPEND_FILE;
		}
		else
			tmp = tmp->next;
	}
}
