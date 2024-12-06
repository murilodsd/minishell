/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_expand_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:57:26 by dramos-j          #+#    #+#             */
/*   Updated: 2024/12/06 11:23:36 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	add_var_token(t_token **token, char *env_var, int j, int i)
{
	char	*tmp;

	tmp = ft_substr(env_var, j, i - j);
	if (check_malloc(tmp))
		return ;
	if (!(*token)->data)
		(*token)->data = ft_strdup(tmp);
	else
	{
		find_place(token, ft_strdup(" "), (*token)->quote, SPACE_TOKEN);
		(*token) = (*token)->next;
		find_place(token, ft_strdup(tmp), (*token)->quote, WORD);
		(*token) = (*token)->next;
	}
	(*token)->type = WORD;
	free(tmp);
}

void	check_var_space(char *env_var, t_token **token)
{
	int		i;
	int		j;
	t_token	*tmp;

	i = 0;
	j = 0;
	tmp = *token;
	while (env_var[i])
	{
		if (ft_isspace(env_var[i]))
		{
			add_var_token(token, env_var, j, i);
			i = ignore_spaces(env_var, i);
			j = i;
		}
		else
			i++;
	}
	add_var_token(token, env_var, j, i);
}
