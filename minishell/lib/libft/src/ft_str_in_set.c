/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_in_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:44:56 by mde-souz          #+#    #+#             */
/*   Updated: 2024/11/16 14:47:14 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

bool	ft_str_in_set(char *str, char *set)
{
	if (!str || !set)
		return (FALSE);
	while (*str)
	{
		if (!ft_strchr(set, *str))
			return (FALSE);
		str++;
	}
	return (TRUE);
}
