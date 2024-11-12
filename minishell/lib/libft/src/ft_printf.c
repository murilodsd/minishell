/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:21:25 by mde-souz          #+#    #+#             */
/*   Updated: 2024/07/17 10:27:53 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isflag(char c)
{
	return (c == '+' || c == '-' || c == ' ' || c == '#'
		|| c == '0' || c == '.');
}

static int	ft_print_args(int fd, va_list args, t_params params)
{
	unsigned int	va_arg_ui;

	if (params.tag == 'd' || params.tag == 'i')
		return (ft_printnbr_fd(va_arg(args, int), params, fd));
	else if (params.tag == 'u')
		return (ft_printnbr_fd((unsigned int)va_arg(args, int), params, fd));
	else if (params.tag == 'c')
		return (ft_printchar_fd(va_arg(args, int), params, fd));
	else if (params.tag == 's')
		return (ft_print_s_fd(va_arg(args, char *), params, fd));
	else if (params.tag == 'x' || params.tag == 'X')
	{
		va_arg_ui = va_arg(args, unsigned int);
		if (params.tag == 'x')
			return (ft_printnbr_base_fd(va_arg_ui, params, BASE16_L, fd));
		else if (params.tag == 'X')
			return (ft_printnbr_base_fd(va_arg_ui, params, BASE16_U, fd));
	}
	else if (params.tag == 'p')
		return (ft_print_p_fd((unsigned long)va_arg(args, long), params, fd));
	else if (params.tag == '%')
		return (ft_putchar_fd('%', fd));
	return (0);
}

static void	get_flags(const char **format, t_params *p_params)
{
	ft_bzero(p_params, sizeof(t_params));
	while (ft_isflag(**format) && **format != '.')
	{
		p_params->flags[(int)(**format)] = 1;
		(*format)++;
	}
	while (ft_isdigit(**format))
	{
		p_params->width = 10 * p_params->width + (**format - '0');
		(*format)++;
	}
	if (**format == '.')
	{
		p_params->flags[(int)(**format)] = 1;
		(*format)++;
		while (ft_isdigit(**format))
		{
			p_params->digits = 10 * p_params->digits + (**format - '0');
			(*format)++;
		}
	}
}

int	ft_loop_format(int fd, const char *format, t_params *params, va_list args)
{
	int	count;

	count = 0;
	while (*format)
	{
		while (*format != '%' && *format)
		{
			count += ft_putchar_fd(*format, fd);
			format++;
		}
		if (*format == '%')
		{
			format++;
			get_flags(&format, params);
		}
		params->tag = *format;
		count += ft_print_args(fd, args, *params);
		if (*format != '\0')
			format++;
	}
	return (count);
}

int	ft_printf(int fd, const char *format, ...)
{
	va_list		args;
	int			count;
	t_params	params;

	if (!format)
		return (-1);
	va_start(args, format);
	count = ft_loop_format(fd, format, &params, args);
	va_end(args);
	return (count);
}
/* #include <stdio.h>
int	main(void)
{
	int a;
 	int	num = -132;
	char	*format = "#0+ 505.31d";
	//ft_putstr_fd(&num,1);
	unsigned int n = num;

	char	*s = NULL;
	char	*s2 = "bitch";
	unsigned int u = 4294967295;
	
	//ft_printf("%23p\n" ,(void*)5251690933477523038lu);
	//printf("%23p\n" ,(void*)5251690933477523038lu);
	//printf("%15p\n", &num);
	//ft_printf("%15p\n", &num);
	//printf("%12p\n", s);
	//ft_printf("%12p\n", s);
	//ft_printf("%.p\n", 'a');
	//printf("%d\n",123);
	//ft_printf("%-#+ 3.4da\n",-123);
	//get_flags(&format,&params);
	//a = 256;
	//while (a--)
	//{
	//	if (params.flags[a])
	//		printf("%c\n",a);
	//}
	//printf("digits %d\n",params.digits);
	//printf("digits %d\n",params.width);
	//printf("%#+5.3d\n",123);
	//ft_printf("%#+.d\n",123);
	//ft_printf("oLA TUDO%d%sbeleza%10c%i%d\n
	//unsigned%u\n",5,"oi",'c',10,"palavra", n);
	//printf("oLA TUDO%d%sbeleza% -10c%i%d\n
	//unsigned%u\n",5,"oi",'c',10,"palavra", n);
	//ft_printf("%x\n",16);
	//printf("%3x\n",16);
	//ft_printf("%p\n",&num);
	//printf("%p\n",&num);
	//ft_printf("%-5%\n");
	//printf("%.2s\n","hello");
	//printf("\n%d",ft_putunbr_base_fd(64684651, "0123456789abcdef", 1));
	//printf("\n%d",ft_putnbr_base_fd(64684651, "0123456789abcdef", 1));
	//printf("\n%d",ft_putnbr_fd(64684651, 1));
	char	*s = NULL;
	printf("\nft_printf %d\n", ft_printf("d %10.3d s %.3s c %10c i %i d 
	%+-8d\nu %u p %p\n x %#x X %25X",5,"oi",'\0',10,8654,9675,s,65486,35468));
	printf("\nprintf %d\n", printf("d %10.3d s %.3s c %10c i %i d 
	%+-8d\nu %u p %p\n x %#x X %25X",5,"oi",'\0',10,8654,9675,s,65486,35468));
} */