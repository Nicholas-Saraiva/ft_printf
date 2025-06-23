/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:27:02 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/06/23 11:30:31 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	string_flag(char *my_arg, int flag, int width, int precision)
{
	int	i;

	i = 0;
	while (my_arg[i])
	{
		if (flag & FLAG_DOT && i > precision)
			break ;
		i += ft_putchar(my_arg[i]);
	}
	while (width > 0 && i < width)
		i += ft_putchar(' ');
	return (i);
}

int	string_noflag(char *my_arg, int flag, int width, int precision)
{
	int	i;
	int j;
	int	len;
	int	size;

	i = 0;
	j = 0;
	size = 0;
	len = ft_strlen(my_arg);
	if (flag & FLAG_DOT)
		len = precision;
	while (width > 0 && len + i++ < width)
		size += ft_putchar(' ');
	while (*my_arg)
	{
		if (flag & FLAG_DOT && j++ > precision)
			break ;
		size += ft_putchar((*my_arg++));
	}
	return (size);
}

int	condition_for_s(int flag, va_list args, int width, int precision)
{
	char	*my_arg;

	my_arg	= va_arg(args, char *);
	if (flag & FLAG_MINUS)
		return (string_flag(my_arg, flag, width, precision));
	else
		return (string_noflag(my_arg, flag, width, precision));
}

