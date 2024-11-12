/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:59:00 by murilodsd         #+#    #+#             */
/*   Updated: 2024/05/02 20:14:45 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** The strlcat() function appends the NUL-terminated string src
 * to the end of dst.
 * It will append at most size - strlen(dst) - 1 bytes,
 * NUL-termi‐nating the result.
 * @param src and dst must be NUL-terminated.
 * @return if size > dest src + dest else src
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dst[i])
		i++;
	j = 0;
	while (i + j + 1 < size && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	while (src[j])
		j++;
	if (size <= i)
		return (j + size);
	return (i + j);
}
/* cd 42	#include <stdio.h>
#include <string.h>
int	main(void)
{
	char *s1 = strdup("abc");
	char s2[] = "bbbbb";
	char *s3 = strdup("abc");
	char s4[] = "bbbbb";
	printf("%ld ", strlcat(s1, s2, 15));
	printf("%s\n", s1);
	printf("%ld ", ft_strlcat(s3, s4, 15));
	printf("%s\n", s3);
	return 0;
} */