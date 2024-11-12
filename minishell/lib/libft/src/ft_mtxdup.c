/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtxdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:48:52 by mde-souz          #+#    #+#             */
/*   Updated: 2024/08/30 10:31:05 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	**ft_mtxdup(char **matrix)
{
	char	**new_matrix;
	size_t	matrix_len;
	int		y;

	if (!matrix)
		return (NULL);
	matrix_len = ft_mtxlen(matrix);
	new_matrix = ft_calloc(matrix_len + 1, sizeof(char *));
	if (!new_matrix)
		return (NULL);
	y = 0;
	while (matrix[y])
	{
		new_matrix[y] = ft_strdup(matrix[y]);
		if (!new_matrix[y])
		{
			ft_free_matrix(new_matrix);
			return (NULL);
		}
		y++;
	}
	return (new_matrix);
}

/* int main(int argc, char const *argv[])
{
	char* matrix[] = {
	"012345678",
	"012345678",
	NULL
	};
	char **new_matrix;

	new_matrix = ft_mtxdup(matrix);
	ft_printf(1, "%s", new_matrix[0]);
	ft_printf(1, "%s", new_matrix[1]);
	return 0;
} */
