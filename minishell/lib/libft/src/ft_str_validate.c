/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:45:24 by mde-souz          #+#    #+#             */
/*   Updated: 2024/11/16 14:41:06 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

bool	ft_str_validate(char *str, bool(*f)(char))
{
	if (!str)
		return (FALSE);
	while (*str)
	{
		if (!f(*str))
			return (FALSE);
		str++;
	}
	return (TRUE);
}
