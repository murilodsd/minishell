/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 19:06:20 by mde-souz          #+#    #+#             */
/*   Updated: 2024/12/09 22:23:33 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_str_replace(char **dest, char *src)
{
	if (!dest)
		return ;
	if (*dest)
		free(*dest);
	*dest = ft_strdup(src);
}
/* int main() {
    char *str = NULL;

    ft_str_replace(&str, "Hello, world!");
    printf("str: %s\n", str);

    ft_str_replace(&str, "Goodbye, world!");
    printf("str: %s\n", str);

    free(str);
    return 0;
} */