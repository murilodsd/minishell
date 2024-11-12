/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:50:03 by mde-souz          #+#    #+#             */
/*   Updated: 2024/05/01 13:30:08 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The  bzero()  function  erases  the  data  in the n bytes of the memory
starting at the location pointed to by s, by writing zeros (bytes  con‐
taining '\0') to that area.
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
/* #include <stdio.h>
int	main(void)
{
	char	s1[] = "cao e gato";
	void *s2 = s1; 
	ft_bzero(s2, (size_t) 5);
	if (s1[4])
		printf("%c",s1[4]);
	else
		printf("\\0");
} */