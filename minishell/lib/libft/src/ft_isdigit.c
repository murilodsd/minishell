/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 20:55:59 by mde-souz          #+#    #+#             */
/*   Updated: 2024/11/16 13:44:58 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/** This function checks if the given character is a digit (0-9).
 * @param c The character to be checked.
 * @return 1 if the character is a digit, 0 otherwise.
 */
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/** This function checks if all characters in the given string are digits.
 * @param str The string to be checked.
 * @return 1 if all characters are digits, 0 otherwise.
 */
bool	ft_isalldigits(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (FALSE);
		str++;
	}
	return (TRUE);
}
/*#include <stdio.h>

int main() {
    char numeros[] = "654";
    char letras[] ="\n";
    printf("So numeros %d\n",ft_str_is_numeric(numeros));
    printf("Com letras %d",ft_str_is_numeric(letras));
    return 0;
}*/