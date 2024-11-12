/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:56:15 by mde-souz          #+#    #+#             */
/*   Updated: 2024/07/06 19:16:58 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;
	size_t	bytes_to_copy;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (!ptr)
		return (calloc(1, new_size));
	new_ptr = calloc(1, new_size);
	if (!new_ptr)
		return (NULL);
	if (old_size < new_size)
		bytes_to_copy = old_size;
	else
		bytes_to_copy = new_size;
	ft_memcpy(new_ptr, ptr, bytes_to_copy);
	free(ptr);
	return (new_ptr);
}
