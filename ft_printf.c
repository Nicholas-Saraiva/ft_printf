/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 21:37:58 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/06/24 01:40:14 by nsaraiva         ###   ########.fr       */
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
	if (**c == 'd' || **c == 'i')
		return (condition_for_d(flag, args, width, precision));



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
