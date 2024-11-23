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
			if (tmp->type == SPACE_TOKEN)
				tmp = tmp->next;
			tmp->type = EOF_TOKEN;
			while (tmp->next && tmp->next->type != SPACE)
			{
				tmp = tmp->next;
				tmp->type = EOF_TOKEN;
			}
		}
		tmp = tmp->next;
	}
}

void	looking_for_env_var(t_shell *shell)
{
	t_token	*tmp;
	t_token	*tmp_next;

	tmp = shell->token;
	while (tmp)
	{
		tmp_next = tmp->next;
		if (tmp->type == ENV_VAR)
		{
			if (tmp == shell->token)
				shell->token = tmp_next;
			rm_token(&tmp, shell);
			check_env_var(tmp_next, shell);
		}
		else if (tmp->type == ENV_VAR_EXIT_CODE)
			check_exit_code(tmp, shell);
		tmp = tmp_next;

	}
}

void	looking_d_quote(t_shell *shell)
{
	t_token	*tmp;
	char	*new_data;

	tmp = shell->token;
	while (tmp)
	{
		if (tmp->quote == DOUBLE && tmp->type != EOF_TOKEN && tmp->data)
		{
			new_data = check_env_var_d_quote(shell, tmp->data);
			if (new_data && ft_strcmp(tmp->data, new_data) != 0)
				ft_str_replace(&(tmp->data), new_data);
			if (new_data)
				free(new_data);
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
			if (tmp->type == SPACE)
				tmp = tmp->next;
			tmp->type = REDIR_IN_FILE;
		}
		else if (tmp->type == REDIR_OUT)
		{
			tmp = tmp->next;
			if (tmp->type == SPACE)
				tmp = tmp->next;
			tmp->type = REDIR_OUT_FILE;
		}
		else if (tmp->type == REDIR_APPEND)
		{
			tmp = tmp->next;
			if (tmp->type == SPACE)
				tmp = tmp->next;
			tmp->type = REDIR_APPEND_FILE;
		}
		else
			tmp = tmp->next;
	}
}
