/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countdec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:52:37 by mde-souz          #+#    #+#             */
/*   Updated: 2024/05/08 12:53:23 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_countdec(long n_long)
{
	int	count;

	if (n_long < 0)
		n_long = -n_long;
	count = 1;
	while (n_long > 9)
	{
		n_long /= 10;
		count++;
	}
	return (count);
}
