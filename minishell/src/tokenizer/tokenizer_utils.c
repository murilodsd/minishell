/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:15:54 by dramos-j          #+#    #+#             */
/*   Updated: 2024/11/29 11:15:55 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	take_out_quotes(char **data, t_token_quote quote)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = malloc(ft_strlen(*data) + 1);
	if (check_malloc(tmp))
		return ;
	while ((*data)[i])
	{
		while ((*data)[i] == '\'' && quote == SINGLE)
			i++;
		while ((*data)[i] == '\"' && quote == DOUBLE)
			i++;
		tmp[j] = (*data)[i];
		i++;
		j++;
	}
	tmp[j] = '\0';
	free(*data);
	*data = tmp;
}

void	add_quote_token(char quote, char *cmd, int i, t_shell *shell)
{
	if (quote == '\"')
		add_token(&shell, ft_substr(cmd, i + 1, 1), ENV_VAR_NAME, DOUBLE);
	else if (quote == '\'')
		add_token(&shell, ft_substr(cmd, i + 1, 1), ENV_VAR_NAME, SINGLE);
}
