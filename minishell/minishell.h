/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:08:29 by dramos-j          #+#    #+#             */
/*   Updated: 2024/10/15 16:43:57 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "./libft/libft.h"
#include <readline/readline.h>
#include <readline/history.h>

typedef struct s_data
{
	char	**envp;
}				t_data;


void	handle_input(char *cmd);

#endif

