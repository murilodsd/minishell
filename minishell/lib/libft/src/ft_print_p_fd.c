/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:26:29 by mde-souz          #+#    #+#             */
/*   Updated: 2024/07/17 10:33:09 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countnbr_hexabase(unsigned long p)
{
	int		count;

	count = 0;
	if (p < 16)
		count ++;
	else
	{
		count += ft_countnbr_hexabase(p / 16);
		count += ft_countnbr_hexabase(p % 16);
	}
	return (count);
}

int	ft_print_p_fd(unsigned long p, t_params params, int fd)
{
	int	count;
	int	length;

	length = ft_strlen("0x") + ft_countnbr_hexabase(p);
	count = 0;
	if (params.flags['-'] != 1)
		while ((p && params.width - count > length)
			|| (!p && params.width - count > (int)ft_strlen("(nil)")))
			count += ft_putchar_fd(' ', fd);
	if (!p)
		count += ft_putstr_fd("(nil)", fd);
	else
	{
		count += ft_putstr_fd("0x", fd);
		count += ft_putnbr_hexabase_fd(p, BASE16_L, fd);
	}
	if (params.flags['-'] == 1)
		while (params.width > count)
			count += ft_putchar_fd(' ', fd);
	return (count);
}
