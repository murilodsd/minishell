/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:54:46 by dramos-j          #+#    #+#             */
/*   Updated: 2024/11/07 18:40:35 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


char	add_type(char *data)
{
	if (data[0] == '|')
		return ('P');
	if (data[0] == '<' || data[0] == '>')
		return ('R');
	else
		return ('C');
}


t_token	*find_last_token(t_token *token)
{
	if (!token)
		return (NULL);
	while (token->next)
		token = token->next;
	return (token);
}

t_token	*new_token(t_token *token, char *data)
{
	t_token	*new_token;

	new_token = malloc(sizeof(t_token));
	if (!new_token)
		return (NULL);
	new_token->data = data;
	new_token->type = add_type(data);
	if (!find_last_token(token))
	{
		new_token->i = 0;
		new_token->prev = NULL;
	}
	else
	{
		new_token->i = find_last_token(token)->i + 1;
		new_token->prev = find_last_token(token);
	}
	new_token->next = NULL;
	return (new_token);
}

t_token	*split_token(char *cmd)
{
	t_token	*token;
	char	*data;
	int		i;
	int		j;

	i = 0;
	j = 0;
	token = NULL;
	while (cmd[i])
	{
		if (cmd[i] == ' ' || cmd[i] == '\t' || cmd[i + 1] == '\0')
		{
			if (cmd[i + 1] == '\0')
			{
				j++;
				i++;
			}
			data = ft_substr(cmd, i - j, j);
			if (!token && data)
				token = new_token(token, data);
			else if (data)
				find_last_token(token)->next = new_token(token, data);
			j = 0;
			while (cmd[i] == ' ' || cmd[i] == '\t')
				i++;
		}
		i++;
		j++;
	}
	return (token);
}

void	lexer(char *cmd)
{
	t_token	*token;

	token = NULL;
	token = split_token(cmd);
	printf("Tokens:\n");
	while (token)
	{
		printf("Token: %s\n", token->data);
		printf("Type: %c\n", token->type);
		printf("Index: %d\n", token->i);
		token = token->next;
	}
}
