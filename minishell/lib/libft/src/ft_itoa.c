/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:52:03 by mde-souz          #+#    #+#             */
/*   Updated: 2024/08/26 16:52:10 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers must be handled.*/

#include "libft.h"

static void	ft_fillarray(char *p, long n_long, size_t size)
{
	p[size] = '\0';
	while (size && p[size - 1] != '-')
	{
		p[--size] = (n_long % 10) + '0';
		n_long /= 10;
	}
}

char	*ft_itoa(int n)
{
	size_t	size;
	size_t	decplaces;
	char	*p;
	long	n_long;

	n_long = n;
	size = 0;
	if (n_long < 0)
	{
		size++;
		n_long *= (-1);
	}
	decplaces = ft_countdec(n_long);
	size = size + decplaces;
	p = (char *)ft_calloc(size + 1, sizeof(char));
	if (!p)
		return (NULL);
	if (size != decplaces)
		p[0] = '-';
	ft_fillarray(p, n_long, size);
	return (p);
}
/* #include <stdio.h>
int	main(void)
{
	printf("%s\n",ft_itoa(-1));
	printf("%s\n",ft_itoa(-121));
	printf("%s\n",ft_itoa(0));
	printf("%s\n",ft_itoa(__INT_MAX__));
} */