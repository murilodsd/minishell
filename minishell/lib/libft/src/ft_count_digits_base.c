/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits_base.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:52:37 by mde-souz          #+#    #+#             */
/*   Updated: 2024/08/06 11:42:17 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_digits_base(long n_long, char *base_to)
{
	int	count;
	int	base_length;

	base_length = ft_strlen(base_to);
	if (n_long < 0)
		n_long = -n_long;
	count = 1;
	while (n_long > base_length - 1)
	{
		n_long /= base_length;
		count++;
	}
	return (count);
}
/* #include <stdio.h>
int main(void)
{
	printf("%d\n",ft_count_digits_base(97,"01"));
	printf("%d\n",ft_count_digits_base(98,"01"));
	printf("%d\n",ft_count_digits_base(49,"01"));
	printf("%d\n",ft_count_digits_base(32,"01"));
	printf("%d\n",ft_count_digits_base(0,"01"));
	printf("%d\n",ft_count_digits_base(1,"01"));
	printf("%d\n",ft_count_digits_base(2,"01"));
	return 0;
} */