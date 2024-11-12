/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:39:19 by mde-souz          #+#    #+#             */
/*   Updated: 2024/09/27 03:59:54 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_save_pointer(t_mem_alloc *mem_allocation, \
	t_list **ptr_or_matrix_list, void *ptr)
{
	t_list	*new_node;

	new_node = ft_lstnew(ptr);
	if (!new_node)
		ft_free_exit_error(mem_allocation, "Failed to allocate mem for a node");
	ft_lstadd_back(ptr_or_matrix_list, new_node);
}
