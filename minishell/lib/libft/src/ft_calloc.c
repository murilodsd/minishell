/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:33:23 by mde-souz          #+#    #+#             */
/*   Updated: 2024/04/22 19:31:18 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The calloc() function allocates memory for an array of  nmemb  elements
of  size bytes each and returns a pointer to the allocated memory.  The
memory is set to zero.  If nmemb or size is 0,  then  calloc()  returns
either  NULL,  or a unique pointer value that can later be successfully
passed to free().  If the multiplication of nmemb and size would result
in  integer  overflow, then calloc() returns an error.  By contrast, an
integer overflow would not be detected in the following  call  to  mal‐
loc(),  with the result that an incorrectly sized block of memory would
be allocated:

           malloc(nmemb * size);*/
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)

{
	void	*p;

	p = malloc(nmemb * size);
	if (!p)
		return (NULL);
	ft_bzero(p, nmemb * size);
	return (p);
}
/* #include <stdio.h>
int	main(void)
{
	char *s1;
	int nmemb = 10;
	s1 = (char *)ft_calloc(nmemb, sizeof(char));
	while (nmemb--)
		if (*s1++)
			printf("%s", s1);
		else
			printf("\\0");
			
} */