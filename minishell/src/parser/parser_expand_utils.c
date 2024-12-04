/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_expand_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:57:26 by dramos-j          #+#    #+#             */
/*   Updated: 2024/12/04 17:21:01 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	add_var_token(t_shell *shell, t_token *token, char *env_var, int j, int i)
{
	char	*tmp;
	t_token	*tmp_token;

	tmp_token = shell->token;
	while (token != tmp_token)
		tmp_token = tmp_token->next;
	tmp = ft_substr(env_var, j, i - j);
	printf("tmp = %s\n", tmp);
	if (check_malloc(tmp))
		return ;
	if (!tmp_token->data)
		tmp_token->data = ft_strdup(tmp);
	else
	{
		find_place(tmp_token, ft_strdup(tmp), token->quote);
		tmp_token = tmp_token->next;
	}
	free(tmp);
}

void	check_var_space(char *env_var, t_token *token, t_shell *shell)
{
	int		i;
	int		j;
	t_token	*tmp_token;

	i = 0;
	j = 0;
	tmp_token = token;
	while (env_var[i])
	{
		if (ft_isspace(env_var[i]))
		{
			add_var_token(shell, tmp_token, env_var, j, i);
			add_space_token(tmp_token);
			tmp_token = tmp_token->next;
			i = ignore_spaces(env_var, i);
			j = i;
			printf("env_var[%d] = %c\n", i, env_var[i]);
		}
		else
			i++;
	}
	add_var_token(shell, tmp_token, env_var, j, i);
}
