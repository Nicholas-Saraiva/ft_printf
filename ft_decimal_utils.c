/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:34:50 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/06/24 02:10:34 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_display_number(int n)
{
	char	nbr;

	nbr = '0' + n;
	return (write(1, &nbr, 1));
}

int	ft_putnbr(int n)
{
	int	size;

	size = 0;
	if (n == -2147483648)
		return (write(1, "2147483648", 10));
	if (n < 0)
		n *= -1;
	if (n > 9)
		size += ft_putnbr(n / 10);
	size += ft_display_number(n % 10);
	return (size);
}

int	ft_decimal_size(int n)
{
	int	len;

	len = 0;
	while (n > 10 || n < -10)
	{
		n /= 10;
		len++;
	}
	return (len + 1);
}

int	ft_minus_d(int n, int width)
{
	int	size;

	size = 0;
	size += ft_putnbr(n);
	while (size < width)
		size += ft_putchar (' ');
	if (n < 0)
		size += write(1, "-", 1);
	return (size);
}

int	pre_print_d(int flag, int width, int len)
{
	int	size;

	size = 0;
	if (!(flag & FLAG_ZERO) && !(flag & FLAG_MINUS))
		while (len + size < width)
			size += ft_putchar (' ');
	if (flag & FLAG_SPACE)
		size += write(1, " ", 1);
	else if (flag & FLAG_PLUS)
		size += write(1, "+", 1);
	return (size);
}

int	condition_for_d(int flag, va_list arg, int width, int precision)
{
	int	n;
	int	size;
	int len;
	
	n =	va_arg(arg, int);
	len = ft_decimal_size(n);
	size = 0;
	if (n < 0)
	{
		size++;
		len++;
		if (flag & FLAG_DOT || flag & FLAG_ZERO)
			write(1, "-", 1);
	}
	size += pre_print_d(flag, width, len);
	if (flag & FLAG_DOT)
		while (len + size < precision + 1)
			size += ft_putchar ('0');
	if (flag & FLAG_ZERO)
		while (len + size < width + 1)
			size += ft_putchar ('0');
	if (flag & FLAG_MINUS)
		size += ft_minus_d(n, width);
	else
	{
		if (n < 0 && !(flag & FLAG_DOT) && !(flag & FLAG_ZERO))
			write(1, "-", 1);
		size += ft_putnbr(n);
	}
	return (size);
}

