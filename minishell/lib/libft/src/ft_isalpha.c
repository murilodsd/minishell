/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 20:16:36 by mde-souz          #+#    #+#             */
/*   Updated: 2024/05/02 14:25:28 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* checks  for an alphabetic character; in the standard "C" locale,
it is equivalent to (isupper(c) ||  islower(c)).   In  some  lo‐
cales, there may be additional characters for which isalpha() is
true—letters which are neither uppercase nor lowercase. */

static int	ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}

static int	ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}

int	ft_isalpha(int c)
{
	return (ft_isupper(c) || ft_islower(c));
}
/* #include <stdio.h>
int main(int argc, char **argv) {
	argc = argc;
    printf("%c e letra %d\n",argv[1][0], ft_isalpha(argv[1][0]));
    return 0;
} */
