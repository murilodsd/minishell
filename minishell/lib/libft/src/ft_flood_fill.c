/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:31:16 by mde-souz          #+#    #+#             */
/*   Updated: 2024/08/30 10:50:26 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	fill(char **tab, t_point size, t_point point, \
	char char_to_fill)
{
	int	x;
	int	y;

	x = point.x;
	y = point.y;
	if (y >= size.y || y < 0 || x >= size.x || x < 0)
		return ;
	if (tab[y][x] != char_to_fill)
		return ;
	tab[y][x] = 'F';
	fill(tab, size, (t_point){x, y + 1}, char_to_fill);
	fill(tab, size, (t_point){x, y - 1}, char_to_fill);
	fill(tab, size, (t_point){x + 1, y}, char_to_fill);
	fill(tab, size, (t_point){x - 1, y}, char_to_fill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	if (begin.y >= size.y || begin.y < 0
		|| begin.x >= size.x || begin.x < 0)
		return ;
	fill(tab, size, begin, tab[begin.y][begin.x]);
}

/* char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}

int main(void)
{
	t_point size = {8, 5};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110101",
		"11100001",
	};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		ft_printf(1, "%s\n", area[i]);
	ft_printf(1, "\n");

	t_point begin = {7, 4};
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		ft_printf(1,"%s\n", area[i]);
	return (0);
} */
