/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:39:02 by dramos-j          #+#    #+#             */
/*   Updated: 2024/12/01 17:28:15 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	split_token(t_token *token, int i)
{
	char	*env_var;
	char	*word;

	env_var = ft_substr(token->data, 0, i);
	if (check_malloc(env_var))
		return ;
	word = ft_substr(token->data, i, ft_strlen(token->data - i + 1));
	if (check_malloc(word))
	{
		free(env_var);
		return ;
	}
	free(token->data);
	token->data = env_var;
	token->type = ENV_VAR_NAME;
	find_place(token, word, token->quote);
}

void	add_next_char(char **data, char c)
{
	char	*tmp;
	char	*next_char;

	tmp = *data;
	next_char = ft_substr(&c, 0, 1);
	*data = ft_strjoin(tmp, next_char);
	free(tmp);
	free(next_char);
}

t_token	*find_redir_file(t_token *tmp, t_token_type type)
{
	tmp = tmp->next;
	if (tmp->type == SPACE_TOKEN)
		tmp = tmp->next;
	if (tmp)
		tmp->type = type;
	while (tmp && tmp->next && (tmp->next->type == WORD
			|| tmp->next->type == ENV_VAR_NAME))
	{
		tmp = tmp->next;
		tmp->type = type;
	}
	return (tmp);
}

void	skip_to_next_pipe(t_token **token)
{
	while (*token && (*token)->type != PIPE)
		*token = (*token)->next;
	if (*token)
		*token = (*token)->next;
}
