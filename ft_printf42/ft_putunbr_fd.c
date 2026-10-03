/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talkhati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:27:39 by talkhati          #+#    #+#             */
/*   Updated: 2025/09/23 18:47:09 by talkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putunbr_fd(unsigned int n, int fd)
{
	char	digit_char;
	int		count;

	count = 0;
	if (n > 9)
		count += ft_putunbr_fd(n / 10, fd);
	digit_char = (n % 10) + '0';
	count += write(fd, &digit_char, 1);
	return (count);
}
