/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:26:58 by mde-souz          #+#    #+#             */
/*   Updated: 2024/11/20 12:42:57 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The  atoi() function converts the initial portion of the string pointed
to by nptr to int. */

#include "../include/libft.h"

int	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

bool	ft_is_atoi_param_max_10(const char *nptr)
{
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	if (!ft_isalldigits((char *)nptr))
		return (FALSE);
	if (ft_strlen(nptr) > 10)
		return (FALSE);
	return (TRUE);
}

long	ft_atoi(const char *nptr)
{
	long	n;
	long	signal;

	signal = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '+')
		nptr++;
	else if (*nptr == '-')
	{
		nptr++;
		signal = -1;
	}
	n = 0;
	while (ft_isdigit(*nptr))
	{
		n = n * 10 + (*nptr - '0');
		nptr++;
	}
	return (n * signal);
}
/* #include <stdio.h>
int	main(void)
{
	printf("%d\n",ft_is_atoi_param_max_10("2147483647"));
	printf("%d\n",ft_is_atoi_param_max_10("2147483648"));
	printf("%d\n",ft_is_atoi_param_max_10("21474836471"));
	printf("%d\n",ft_is_atoi_param_max_10("-2147483648"));
	printf("%d\n",ft_is_atoi_param_max_10("-21474836410"));
	printf("%d\n",ft_atoi("5"));
	printf("%d\n",ft_atoi("0"));
	printf("%d\n",ft_atoi(""));
	printf("%d\n",ft_atoi("22a"));
	printf("%d\n",ft_atoi("a22a"));
	printf("%d\n",ft_atoi("    -22a"));
	printf("%d\n",ft_atoi("+22a"));
	printf("%d\n",ft_atoi("2147483647"));
	printf("%d\n",ft_atoi("-2147483648"));
} */