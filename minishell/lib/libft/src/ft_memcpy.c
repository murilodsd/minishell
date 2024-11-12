/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:19:06 by mde-souz          #+#    #+#             */
/*   Updated: 2024/05/01 15:50:48 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** The  ft_memcpy()  function  copies  n bytes 
 * from memory area src to memory area dest.
 * The memory areas must not overlap.
 * Use memmove(3)  if  the memory areas do overlap.
 * @return pointer to dest, if both params are null it returns null
 * There is no difference casting to char or unsigned char
*/

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	if (!dest && !src)
		return (NULL);
	d = (char *)dest;
	s = (const char *)src;
	while (n--)
		*d++ = *s++;
	return (dest);
}
/* #include <string.h>
int	main(void)
{
	char *p;
	memcpy(p,NULL,14);
} */