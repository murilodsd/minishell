/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:58:36 by dramos-j          #+#    #+#             */
/*   Updated: 2024/12/14 17:06:08 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTS_H
# define PRINTS_H
# include "minishell.h"

// print.c
char		*format_data_parentheses(const char *data);
const char	*get_token_type_str(t_token_type type);
const char	*get_token_quote_str(t_token_quote quote);
void		print_list(t_token *token);
char		*get_node_type_name(t_node_type type, void *node);
void		print_tree(void *node, int level, bool is_root);

#endif
