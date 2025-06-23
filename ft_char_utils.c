/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:26:26 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/06/23 18:16:05 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	char_flag(char my_arg, int width)
{
	int	i;
	
	i = 0;
	ft_putchar(my_arg);
	while (width - i > 1)
		i += ft_putchar(' ');
	return (i);
}

int	char_noflag(char my_arg, int width)
{
	int i;

	i = 0;
	while (width - i > 1)
		i += ft_putchar(' ');
	i += ft_putchar(my_arg);
	return (i);
}

int	condition_for_c(int flag, va_list args, int width)
{
	char	my_arg;

	my_arg	= (char)va_arg(args, int);
	if (!my_arg)
		my_arg = '\0';
	if (flag & FLAG_MINUS)
		return (char_flag(my_arg, width));
	else
		return (char_noflag(my_arg, width));
}

