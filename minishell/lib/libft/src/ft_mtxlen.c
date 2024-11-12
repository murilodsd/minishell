/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtxlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:56:05 by mde-souz          #+#    #+#             */
/*   Updated: 2024/08/30 10:30:41 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * Calculates the length of a matrix.
 *
 * This function takes a matrix represented as an array of strings and
 * calculates the number of elements in the matrix.
 *
 * @param matrix The matrix to calculate the length of.
 * @return The length of the matrix.
 */

size_t	ft_mtxlen(char **matrix)
{
	size_t	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}
/* int main(int argc, char const *argv[])
{
	(void)argc;
	(void)argv;
	char* matrix[] = {
	"012345678",
	"012345678",
	NULL
	};
	ft_printf(1, "%d", ft_mtxlen(matrix));
	return 0;
} */
