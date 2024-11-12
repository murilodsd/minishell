/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:39:07 by mde-souz          #+#    #+#             */
/*   Updated: 2024/05/02 14:12:36 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** The  memmove()  function  copies n bytes from memory area src to memory
 * area dest.  The memory areas may overlap: copying takes place as though
 * the  bytes in src are first copied into a temporary array that does not
 * overlap src or dest, and the bytes are then copied from  the  temporary
 * array to dest.
 * @return pointer to dest.
Para evitar sobreescrevermos a area de memoria que ainda vamos utilizar
fazemos uma condicional para ou comecar copiando do comecou ou do final*/

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = dest;
	s = src;
	if (d < s)
	{
		while (n--)
			*d++ = *s++;
	}
	else if (d > s)
	{
		while (n--)
			d[n] = s[n];
	}
	return (dest);
}
/* #include <stdio.h>
int	main(int argc, char **argv)
{
	(void)argc;
	char *s = argv[1];
	size_t n = (size_t)atoi(argv[2]);
	ft_memmove(s+1,s,n);
	printf("%s",s);
} */
/* #include <string.h>
int main(int argc, char **argv)
{
	(void) argc;
	char *s1 = strdup(argv[1]);
	char *s2 = strdup(argv[1]);
	int n = atoi(argv[2]);
	printf("\n\t>>> USING ft_memmove() <<<\n\n");
	printf("Sending s1 = \'%s\'\n", s1);
	ft_memmove(s1+1, s1, n);
	printf("Returning \'%s\'\n", s1);
	printf("\n\t>>> USING memmove() <<<\n\n");
	printf("Sending s2 = \'%s\'\n", s2);
	memmove(s2+1, s2, n);
	printf("Returning \'%s\'\n", s2);
	if(s1)
		free(s1);
	if(s2)
		free(s2);
} */