/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s_c_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:35:41 by mde-souz          #+#    #+#             */
/*   Updated: 2024/06/21 16:40:59 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	printwidth(t_params params, int length, int *p_count, int fd)
{
	if (params.flags['-'] != 1)
	{
		while (params.width - *p_count > length)
			*p_count += ft_putchar_fd(' ', fd);
	}
	else
	{
		while (params.width > *p_count)
			*p_count += ft_putchar_fd(' ', fd);
	}
}

int	ft_printchar_fd(char c, t_params params, int fd)
{
	int	count;
	int	length;

	length = 1;
	count = 0;
	if (params.flags['-'] != 1)
		printwidth(params, length, &count, fd);
	count += ft_putchar_fd(c, fd);
	if (params.flags['-'] == 1)
		printwidth(params, length, &count, fd);
	return (count);
}

int	ft_print_s_fd(char *s, t_params params, int fd)
{
	int	count;
	int	length;

	length = 0;
	if (s && params.flags['.'] && params.digits < (int)ft_strlen(s))
		length = params.digits;
	else if (s && !(params.flags['.'] && params.digits < (int)ft_strlen(s)))
		length = ft_strlen(s);
	else if (!s && (params.digits >= 6 || !params.flags['.']))
		length = ft_strlen("(null)");
	count = 0;
	if (params.flags['-'] != 1)
		printwidth(params, length, &count, fd);
	if (!s && (!params.flags['.'] || params.digits >= 6))
		count += ft_putstr_fd("(null)", fd);
	else
	{
		while (length--)
			count += ft_putchar_fd(*(s++), fd);
	}
	if (params.flags['-'] == 1)
		printwidth(params, length, &count, fd);
	return (count);
}
/* #include <stdio.h>
 int main(void)
{
	Params	params;

	char	*s = NULL;
	params.digits = 0;
	params.width = 23;
	params.flags[' '] = 0;
	params.flags['-'] = 0;
	params.flags['+'] = 0;
	params.flags['.'] = 0;
	params.flags['0'] = 0;
	
	printf("%23sa\n",s);
	ft_print_s_fd(s,params,1);
	printf("a\n");
	return 0;
} */