/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_exit_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:36:15 by mde-souz          #+#    #+#             */
/*   Updated: 2024/09/22 18:36:20 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_free_exit_error(t_mem_alloc *mem_allocation, \
	char *error_msg)
{
	if (errno)
		ft_printf(2, "Error\n%s: %s\n", error_msg, strerror(errno));
	else
		ft_printf(2, "Error\n%s\n", error_msg);
	if (mem_allocation->ptr_mem_list != NULL)
		ft_lstclear(&(mem_allocation->ptr_mem_list), free);
	if (mem_allocation->matrix_mem_list != NULL)
		ft_lstclear(&(mem_allocation->matrix_mem_list), ft_free_matrix);
	exit(EXIT_FAILURE);
}
