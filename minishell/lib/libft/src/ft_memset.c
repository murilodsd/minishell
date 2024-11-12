/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:43:18 by mde-souz          #+#    #+#             */
/*   Updated: 2024/05/01 13:32:08 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The  memset()  function  fills  the  first  n  bytes of the memory area
** pointed to by s with the constant byte c. 
** The memset() function returns a pointer to the memory area s.
*/
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*p;

	p = s;
	while (n--)
	{
		*p++ = (char)c;
	}
	return (s);
}
/* #include <stdio.h>
int	main(int argc , char** argv)
{
	(void)argc;
	int size = atoi(argv[2]);
	int* s = (int*)malloc(sizeof(size));
	unsigned char* p;
	p = ft_memset(s, argv[1][0], size);
	while (size--)
		printf("%c",*p++);
	free(s);
} */