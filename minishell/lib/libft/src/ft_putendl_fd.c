/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:25:21 by mde-souz          #+#    #+#             */
/*   Updated: 2024/05/02 14:21:43 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Outputs the string 's' to the given file descriptor
 * followed by a newline.
 *
 * @param s The string to be outputted.
 * @param fd The file descriptor to write the string to.
 */
void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
/* #include <stdio.h>
#include <stdlib.h>
int	main(int argc, char **argv)
{
	argc = argc;
	ft_putendl_fd(argv[1],atoi(argv[2]));
} */