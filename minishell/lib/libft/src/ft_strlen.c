/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:28:59 by mde-souz          #+#    #+#             */
/*   Updated: 2024/11/16 19:27:05 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The strlen() function calculates the length of the string pointed to by
       s, excluding the terminating null byte ('\0').
       The strlen() function returns the number of bytes in the string pointed
       to by s.
*/

#include "../include/libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}
/* #include <stdio.h>
int	main(void)
{
	char b[10] = "a a";
	char *str;
	str = &b[0];
	printf("Tamanho da string Palavra!!! eh: %ld ", ft_strlen(str));
} */