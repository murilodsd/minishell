/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:58:15 by mde-souz          #+#    #+#             */
/*   Updated: 2024/05/01 16:05:13 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** The memcmp() function compares the first n bytes 
 * (each interpreted as unsigned char) of the memory areas s1 and s2.
 * Aqui faz diferença ser char ou unsigned char,
 * pois a comparacao acaba sendo em inteiro entao ser -1 ou 128 fara diferenca
 */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (!n)
		return (0);
	while (--n)
	{
		if (*(unsigned char *)s1 != *(unsigned char *)s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
/* #include <stdio.h>
int	main(void)
{
	printf("%d\n",ft_memcmp("","paoasd",0));
} */