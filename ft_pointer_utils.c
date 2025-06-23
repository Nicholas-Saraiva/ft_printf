/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:34:50 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/06/23 19:31:25 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_p(unsigned long long n)
{
    int		size;
    char	*base;

    size = 0;
    base = "0123456789abcdef";
    if (n > 16)
        size += ft_puthex_p(n / 16);
    size += write(1, &base[n % 16], 1);
    return (size);
}

int	ft_strhex_len(unsigned long long n)
{
	int	len;

	len = 0;
	while (n > 16)
	{
		n /= 16;
		len++;
	}
	return (len + 3);
}

int	ft_minus_p(unsigned long long n, int width)
{
	int	size;

	size = 0;
	size += ft_puthex_p(n);
	while (size + 2 < width)
		size += ft_putchar (' ');
	return (size);
}

int	pre_print_p(unsigned long long n, int flag, int width, int len)
{
	int	size;

	size = 0;
	if (!(flag & FLAG_ZERO) && !(flag & FLAG_MINUS))
		while (len + size < width)
			size += ft_putchar (' ');
	if (!n)
	{
		size += write(1, "(nil)", 5);	
		return (size);
	}
	if (flag & FLAG_SPACE)
		size += write(1, " ", 1);
	else if (flag & FLAG_PLUS)
		size += write(1, "+", 1);
	size += write(1, "0x", 2);
	return (size);
}

int	condition_for_p(int flag, va_list arg, int width)
{
	unsigned long long n;
	int	size;
	int len;
	
	n = (unsigned long long) va_arg(arg, void *);
	len = ft_strhex_len(n);
	size = pre_print_p(n, flag, width, len);
	if (n && flag & FLAG_ZERO)
		while (len + size < width)
			size += ft_putchar ('0');
	if (flag & FLAG_MINUS)
		ft_minus_p(n, width);
	else if (n)
		ft_puthex_p(n);
	return (size);
}

