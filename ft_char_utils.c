/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:26:26 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/06/23 11:26:39 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	char_flag(char my_arg, int width)
{
	int	i;
	
	i = 1;
	ft_putchar(my_arg);
	while (width - i++ > 0)
		ft_putchar(' ');
	return (i - 1);
}

int	char_noflag(char my_arg, int width)
{
	int i;

	i = 1;
	while (width - i++ > 0)
		ft_putchar(' ');
	ft_putchar(my_arg);
	return (i - 1);
}

int	condition_for_c(int flag, va_list args, int width)
{
	char	my_arg;

	my_arg	= (char)va_arg(args, int);
	if (flag & FLAG_MINUS)
		return (char_flag(my_arg, width));
	else
		return (char_noflag(my_arg, width));
}

