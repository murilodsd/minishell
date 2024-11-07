/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:08:29 by dramos-j          #+#    #+#             */
/*   Updated: 2024/11/07 17:46:37 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "./libft/libft.h"
#include <readline/readline.h>
#include <readline/history.h>

typedef struct	s_token
{
	char	*data;
	char	type;
	int		i;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;


void	handle_input(char *cmd);
void	lexer(char *cmd);

#endif

