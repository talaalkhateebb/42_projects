/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointerchar_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talkhati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:28:44 by talkhati          #+#    #+#             */
/*   Updated: 2025/09/25 12:32:57 by talkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_putnbrhexptr_fd(unsigned long long n, int fd)
{
	char	digit_char;
	int		count;

	count = 0;
	if (n >= 16)
		count += ft_putnbrhexptr_fd(n / 16, fd);
	if ((n % 16) < 10)
		digit_char = '0' + (n % 16);
	else
		digit_char = 'a' + ((n % 16) - 10);
	count += write(fd, &digit_char, 1);
	return (count);
}

int	ft_ptr_fd(unsigned long long n, int fd)
{
	int	count;

	count = 0;
	if (n == 0)
		return (write(fd, "(nil)", 5));
	count += write(fd, "0x", 2);
	count += ft_putnbrhexptr_fd(n, fd);
	return (count);
}
