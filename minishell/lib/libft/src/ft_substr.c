/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:14:27 by mde-souz          #+#    #+#             */
/*   Updated: 2024/04/30 17:37:01 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Extracts a substring from a given string.
 *
 * Allocates (with malloc(3)) and returns a substring
 * from the string ’s’.
 * The substring begins at index ’start’ and is of
 * maximum size ’len’.
 *
 * @param s The original string from which the substring will be extracted.
 * @param start The starting index of the substring.
 * @param len The length of the substring.
 * @return The substring as a newly allocated string
 * or NULL if memory allocation fails.
 */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	substr_s;
	size_t	s_length;
	int		i;

	s_length = ft_strlen(s);
	if (*s == '\0' || start >= s_length)
		return (ft_strdup(""));
	else if (len <= s_length - (size_t)start)
		substr_s = len;
	else
		substr_s = s_length - (size_t)start;
	substr = (char *)malloc(sizeof(char) * (substr_s + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (s[i + start] && len--)
	{
		substr[i] = s[i + start];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
/* #include <stdio.h>
#include <string.h>
int	main(void)
{
	printf("%s",ft_substr("ab\0",1,1));
} */