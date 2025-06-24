/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:34:50 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/06/24 17:33:46 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_display_number(int n)
{
	char	nbr;

	nbr = '0' + n;
	return (write(1, &nbr, 1));
}

static int	ft_putnbr(int n)
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

static int	signal_flag(int n, int flag)
{
	if (flag & FLAG_PLUS)
	{
		if (n >= 0)
			return (write(1, "+", 1)); 
		return (write(1, "-", 1));
	}
	if (flag & FLAG_SPACE)
	{
		if (n >= 0)
			return (write(1," ", 1));
		return (write(1, "-", 1));
	}
	if (n < 0)
		return (write(1, "-", 1));
	return (0);
}

static int	decimal_len(int n)
{
	int	i;

	i = 0;
	while (n > 10 || n < -10)
	{
		n /= 10;	
		i++;
	}
	return (i + 1);
}

static int	decimal_flag(int n, int flag, int width, int precision)
{
	int	i;
	int len;

	i = 0;
	len = decimal_len(n);
	i += signal_flag(n, flag);
	while (precision > len && precision - len > i + 1)
		i += write(1, "0", 1);
	i += ft_putnbr(n);
	while (width > 0 && i < width)
		i += ft_putchar(' ');
	return (i);
}

int	decimal_noflag(int n, int flag, int width, int precision)
{
	int	i;
	int	j;
	int len;
	int	size;

	i = 0;
	j = 0;
	len = decimal_len(n);
	size = len;
	if (flag & FLAG_DOT && precision > len)
		size = precision + 1;
	if (flag & FLAG_PLUS || flag & FLAG_SPACE || n < 0)
		i++;
	if (flag & FLAG_ZERO)
		signal_flag(n, flag);
	while (width && width > size && width - (size) > i)
	{
		if (!(flag & FLAG_ZERO))
			i += ft_putchar(' ');
		else
			i += ft_putchar('0');
	}
	if (!(flag & FLAG_ZERO))
		signal_flag(n, flag);
	while (precision > len && precision - len + 1 > j++)
		i += write(1, "0", 1);
	i += ft_putnbr(n);
	return (i);
}



int	condition_for_decimal(int flag, va_list args, int width, int precision)
{
	int	my_arg;

	my_arg	= va_arg(args, int);
	if (flag & FLAG_MINUS)
		return (decimal_flag(my_arg, flag, width, precision));
	else
		return (decimal_noflag(my_arg, flag, width, precision));
}
