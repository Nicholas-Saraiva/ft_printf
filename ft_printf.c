/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 21:37:58 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/06/23 11:47:13 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_condition(int flag, const char **c, va_list args)
{
	int			width;
	int			precision;

	width = 0;
	precision = -1;
	fill_measures(&width, &precision, c, &flag);
	if (**c == 'c')
		return (condition_for_c(flag, args, width));
	if (**c == 's')
		return (condition_for_s(flag, args, width, precision));
	if (**c == 'p')
		return (condition_for_p(flag, args, width));


	return (1);
}

int	ft_printf(const char *fstring, ...)
{
	va_list	args;
	const char	*c;
	int		size;

	va_start(args, fstring);
	c = fstring;
	size = 0;
	while (*c)
	{
		if(*c != '%')
		{
			ft_putchar(*c);
			size++;
		}
		else
		{
			c++;
			size += check_condition(fill_flags(&c), &c, args);
		}
		c++;
	}
	va_end(args);
	return (size);
}
/*
#include <stdio.h>
int	main()
{
	int a = ft_printf("%1c\n", '5');
	int b = ft_printf("%-1c\n", '5');

	int c = printf("%1c\n", '5');
	int d = printf("%-1c\n", '5');

	printf("%d-%d-%d-%d", a, b, c,d);
	//printf("aaaaaaaaaaaaaaaaa %-10#c \\_O,o_/)\n", 'o');

	int a = ft_printf("A: %-1.1s\n", "Abacaxi Radioativo");
	int d = printf("D: %-1.1s\n", "Abacaxi Radioativo");
	printf("%d-%d", a, d);
	int a = 14;

	printf("%-20p\n", &a);
	ft_printf("%-20p\n", &a);
}*/
