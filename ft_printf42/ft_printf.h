/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talkhati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 18:06:15 by talkhati          #+#    #+#             */
/*   Updated: 2025/09/25 13:08:50 by talkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>
# include <stdarg.h>
# include <stdio.h>

size_t	ft_strlen(const char *s);
int		ft_putnbr_fd(int n, int fd);
int		ft_putnbrhexup_fd(unsigned int n, int fd);
int		ft_putunbr_fd(unsigned int n, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putchar_fd(char c, int fd);
int		ft_ptr_fd(unsigned long long n, int fd);
int		ft_putnbrhexlo_fd(unsigned int n, int fd);
int		ft_printf(const char *format, ...);
#endif
