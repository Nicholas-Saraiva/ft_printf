/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:26:44 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/08/15 12:48:29 by nsaraiva         ###   ########.fr       */
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
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		n *= -1;
		size += write(1, "-", 1);
	}
	if (n > 9)
		size += ft_putnbr(n / 10);
	size += ft_display_number(n % 10);
	return (size);
}

int	ft_print_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}
