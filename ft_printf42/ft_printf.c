/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talkhati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:38:54 by talkhati          #+#    #+#             */
/*   Updated: 2025/09/25 14:15:11 by talkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	type(char c, va_list args)
{
	int	total_chars;

	total_chars = 0;
	if (c == 'd' || c == 'i')
		total_chars += ft_putnbr_fd(va_arg(args, int), 1);
	else if (c == 's')
		total_chars += ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'u')
		total_chars += ft_putunbr_fd(va_arg(args, unsigned int), 1);
	else if (c == 'c')
		total_chars += ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 'X')
		total_chars += ft_putnbrhexup_fd(va_arg(args, int), 1);
	else if (c == 'x')
		total_chars += ft_putnbrhexlo_fd(va_arg(args, int), 1);
	else if (c == 'p')
		total_chars += ft_ptr_fd(va_arg(args, unsigned long long), 1);
	else if (c == '%')
		total_chars += write(1, "%", 1);
	return (total_chars);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total_chars;

	total_chars = 0;
	va_start(args, format);
	if (format == NULL)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			total_chars += type(*format, args);
			format++;
		}
		else
		{
			total_chars += write(1, format, 1);
			format++;
		}
	}
	va_end(args);
	return (total_chars);
}
// #include <stdio.h>
// int main ()
// {
// // char t[]="tala";
// //     ft_printf("Integer: %d\n", -123);
// //     ft_printf("String: %s\n", "Hello");
// //     ft_printf("Unsigned: %u\n", 4294967295U);
// //     ft_printf("Char: %c\n", 'A');
// //     ft_printf("adress: %p\n", t);
// //     printf("adress: %p\n", t);
// //     ft_printf("Hex (lower): %x\n", 10);
// //     ft_printf("Hex (upper): %X\n",25568u );
// //     ft_printf("Percent: %%\n");
// // return 0;
// int f = ft_printf(NULL);
// ft_printf("%d\n" , f);
// // int y = printf(NULL);
// // printf("%d\n" , y);
// }
