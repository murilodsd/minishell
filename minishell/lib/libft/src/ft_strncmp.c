/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:46:35 by mde-souz          #+#    #+#             */
/*   Updated: 2024/04/30 17:59:06 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The  strcmp()  function compares the two strings s1 and s2.  The locale
       is not taken into account (for  a  locale-aware  comparison,  see  str‐
       coll(3)).  The comparison is done using unsigned characters.

       strcmp() returns an integer indicating the result of the comparison, as
       follows:

       • 0, if the s1 and s2 are equal;

       • a negative value if s1 is less than s2;

       • a positive value if s1 is greater than s2.

       The strncmp() function is similar, except it compares  only  the  first
       (at most) n bytes of s1 and s2.
 */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 && --n && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
/* #include <stdio.h>
#include <string.h>

int	main(void)
{	
	char s1[] = "\0";
	char s2[] = "\200";
	size_t	n = 1;
	printf("%d \n",s1,s2,ft_strncmp("zyxbcdefgh", "abcdwxyz", 0));
	printf("%d \n",s1,s2,strncmp("zyxbcdefgh", "abcdwxyz", 0));
	printf("%s e %s, resultado: %d \n",s1,s2,ft_strncmp(s1,s2,n));
} */