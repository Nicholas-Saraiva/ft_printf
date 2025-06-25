/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:27:02 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/06/25 10:31:24 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	condition_for_s(va_list args)
{
	char	*my_arg;
	int		size;

	size = 0;
	my_arg = va_arg(args, char *);
	if (!my_arg)
		return (write(1, "(null)", 6));
	while (*my_arg)
		size += ft_putchar(*my_arg++);
	return (size);
}
