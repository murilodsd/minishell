/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:05:14 by mde-souz          #+#    #+#             */
/*   Updated: 2024/05/02 16:03:19 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must end
with a NULL pointer.
The array of new strings resulting from the split.
NULL if the allocation fails.*/

#include "libft.h"

static int	ft_count_str(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			count++;
		s++;
	}
	return (count);
}

static size_t	ft_strlen_c(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static void	ft_free_allocated_mem(char **p, int i)
{
	while (i >= 0)
	{
		free(p[i]);
		p[i--] = NULL;
	}
	free(p);
	p = NULL;
}

static char	**ft_fillarray_c(char	**p, char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			p[i] = (char *)malloc(sizeof(char) * (ft_strlen_c(s, c)) + 1);
			if (!p[i])
			{
				ft_free_allocated_mem(p, i - 1);
				return (NULL);
			}
			j = 0;
			while (*s && *s != c)
				p[i][j++] = *s++;
			p[i][j] = '\0';
			i++;
		}
		else
			s++;
	}
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	**p;

	p = (char **)ft_calloc(sizeof(char *), (ft_count_str(s, c) + 1));
	if (!p)
		return (NULL);
	return (ft_fillarray_c(p, s, c));
}
/* #include <stdio.h>
int	main(void)
{	
	int	words = 4;
	char 	**p;
	int	i;
	p = ft_split("__string1_string2_string3___string4_",'_');
	i = 0;
	while (i < words)
	{
		printf("%s",*(p + i));
		free(*(p + i++));
	}
	free((p));
} */