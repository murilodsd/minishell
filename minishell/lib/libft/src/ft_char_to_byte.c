/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_to_byte.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:52:03 by mde-souz          #+#    #+#             */
/*   Updated: 2024/07/17 11:38:59 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers must be handled.*/

#include "libft.h"

static void	ft_fillarray(char *p, unsigned char c, size_t size)
{
	p[size] = '\0';
	while (size--)
	{
		p[size] = (c % 2) + '0';
		c /= 2;
	}
}

char	*ft_char_to_byte(unsigned char c)
{
	char	*p;

	p = (char *)malloc(sizeof(char) * (8 + 1));
	if (!p)
		return (NULL);
	ft_fillarray(p, c, 8);
	return (p);
}
/* #include <stdio.h>
int	main(void)
{
	printf("%s\n",ft_char_to_byte('a'));
	printf("%s\n",ft_char_to_byte('b'));
	printf("%s\n",ft_char_to_byte('1'));
	printf("%s\n",ft_char_to_byte(' '));
	printf("%s\n",ft_char_to_byte(255));
	printf("%s\n",ft_char_to_byte(-1));
} */