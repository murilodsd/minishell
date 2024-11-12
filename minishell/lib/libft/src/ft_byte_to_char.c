/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_byte_to_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:26:58 by mde-souz          #+#    #+#             */
/*   Updated: 2024/08/06 11:46:57 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Converts a byte represented as 8 bits to its corresponding character.
 *
 * @param byte The byte to be converted.
 * @return The corresponding character value of the byte.
 *         Returns -1 if the byte is invalid or not 8 bits long.
 */
int	ft_byte_to_char(char *byte)
{
	int	n;

	if (!byte || !*byte || ft_strlen(byte) != 8)
		return (-1);
	n = 0;
	while (*byte)
	{
		if (*byte != '0' && *byte != '1')
			return (-1);
		n = n * 2 + (*byte - '0');
		byte++;
	}
	return (n);
}
/* #include <stdio.h>
int	main(void)
{
	printf("%d\n",ft_byte_to_char("01100001"));
	printf("%d\n",ft_byte_to_char("01100010"));
	printf("%d\n",ft_byte_to_char("00110001"));
	printf("%d\n",ft_byte_to_char("00100000"));
} */