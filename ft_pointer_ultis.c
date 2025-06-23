/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_ultis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:34:50 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/06/23 11:35:00 by nsaraiva         ###   ########.fr       */
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

int	condition_for_p(int flag, va_list arg, int width)
{
	unsigned long long n;
	int	size;
	int len;
	int	i;

	size = 0;
	i = 0;
	n = (unsigned long long) va_arg(arg, void *);
	len = ft_strhex_len(n);
	if (!(flag & FLAG_ZERO) && !(flag & FLAG_MINUS))
		while (len + i++ < width)
			size += ft_putchar (' ');
	if (flag & FLAG_SPACE)
		size += write(1, " ", 1);
	else if (flag & FLAG_PLUS)
		size += write(1, "+", 1);
	size += write(1, "0x", 2);
	if (flag & FLAG_ZERO)
		while (len + i++ < width)
			size += ft_putchar ('0');
	if (flag & FLAG_MINUS)
		ft_minus_p(n, width);
	else
		ft_puthex_p(n);
	return (size);
}

