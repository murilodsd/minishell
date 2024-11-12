/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 05:19:30 by murilodsd         #+#    #+#             */
/*   Updated: 2024/05/02 16:51:48 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** The  strchr() function returns a pointer to the first occurrence of the
 * character c in the string s.
 * Fazemos uma transformaçao para char. assim garantimos que serao os dois char.
 */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
/* #include <stdio.h>
int 	main(void)
{
	char c = 128;
	char s[]= "inicioIfim";
	s[6] = '\200';
 	printf("%d\n",c);
	printf("%d\n",(unsigned char)c);
	char *result = ft_strchr(s,-128);
	if (result)
		printf("%s\n",result);
	else
		printf("Nao encontrou\n");
} */