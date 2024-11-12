/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:19:18 by mde-souz          #+#    #+#             */
/*   Updated: 2024/04/18 15:03:51 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Applies the function `f` to each character of the string `s`,
 * passing its index as the first argument.
 *
 * @param s The string to iterate over.
 * @param f The function to apply to each character.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}
/* #include <ctype.h>
#include <stdio.h>

void to_upper(unsigned int i, char *c)
{
    // Converte o caractere para maiúsculo se par
    if(i%2==0)
    *c = toupper(*c);
}
int main(int argc, char **argv)
{
	argc = argc;
	ft_striteri(argv[1], to_upper);
	printf("%s", argv[1]);
} */