/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_mem_alloc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:41:24 by mde-souz          #+#    #+#             */
/*   Updated: 2024/09/22 18:36:20 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_check_mem_alloc(t_mem_alloc *mem_allocation, \
	t_list **ptr_or_matrix_list, void *ptr, char *error_msg)
{
	if (!ptr)
		ft_free_exit_error(mem_allocation, error_msg);
	else
		ft_save_pointer(mem_allocation, ptr_or_matrix_list, ptr);
}
