/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:48:55 by mde-souz          #+#    #+#             */
/*   Updated: 2024/04/30 17:59:30 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocates (with malloc(3)) and returns a copy of
’s1’ with the characters specified in ’set’ removed
from the beginning and the end of the string. */

#include "libft.h"

static int	ft_ischarset(char c, char const *set)
{
	while (*set)
	{
		if (c == *set++)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	int		i;
	int		j;

	i = 0;
	while (s1[i] && ft_ischarset(s1[i], set))
		i++;
	j = ft_strlen(s1);
	j--;
	while (s1[j] && ft_ischarset(s1[j], set))
		j--;
	s2 = ft_substr(s1, i, j - i + 1);
	return (s2);
}
/* #include <stdio.h>
int	main(void)
{
	printf("%s",ft_strtrim("---_s-tring_principa****l_*-","_-"));
} */