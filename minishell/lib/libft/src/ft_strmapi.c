/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:12:09 by mde-souz          #+#    #+#             */
/*   Updated: 2024/04/24 16:59:42 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Applies the function f to each character of the
string s, passing its index as the first argument
and the character itself as the second. A new
string is created (using malloc(3)) to collect the
results from the successive applications of f. */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*p;

	len = ft_strlen(s);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	p[len] = '\0';
	while (len--)
		p[len] = f(len, s[len]);
	return (p);
}
/* #include <ctype.h>
#include <stdio.h>
char to_upper(unsigned int i, char c)
{
    // Converte o caractere para maiúsculo se par
	if(i%2==0)
		return(toupper(c));
	return (c);
}
int	 main(void)
{
	char	*s1;

	s1 = ft_strmapi("abcdef", to_upper);
	printf("%s", s1);
} */