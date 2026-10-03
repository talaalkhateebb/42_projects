/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhexup_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talkhati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:27:12 by talkhati          #+#    #+#             */
/*   Updated: 2025/09/25 12:31:17 by talkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbrhexup_fd(unsigned int n, int fd)
{
	char	digit_char;
	int		count;

	count = 0;
	if (n >= 16)
		count += ft_putnbrhexup_fd(n / 16, fd);
	if ((n % 16) < 10)
		digit_char = '0' + (n % 16);
	else
		digit_char = 'A' + ((n % 16) - 10);
	count += write(fd, &digit_char, 1);
	return (count);
}
