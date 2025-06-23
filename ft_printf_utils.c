/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:26:44 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/06/23 11:28:15 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

int	is_flag(char c)
{
	if (c == '-' || c == '0' || c == '.' || c == '#' || c == ' ' || c == '+')
		return (1);
	return (0);
}

int	is_number(char my_char)
{
	if (my_char >= '0' && my_char <= '9')
		return (1);
	return (0);
}

int	fill_flags(const char **c)
{
	int			flag;

	flag = 0;
	while (is_flag(**c))
	{
		if (**c == '-')
			flag |= FLAG_MINUS;
		if (**c == '.')
		{
			flag |= FLAG_DOT;
			break ;
		}
		if (**c == '0')
			flag |= FLAG_ZERO;
		if (**c == '#')
			flag |= FLAG_HASH;
		if (**c == '+')
			flag |= FLAG_PLUS;
		if (**c == ' ')
			flag |= FLAG_SPACE;
		(*c)++;
	}
	return flag;
}

void	fill_measures(int *width, int *precision, const char **c, int *flag)
{
	int	new_precision;

	new_precision = -1;
	while (is_number(**c))
	{
		*width = *width*9 + **c - '0';
	   (*c)++;	
	}
	if (**c == '.')
	{
		(*c)++;
		*flag |= FLAG_DOT;
		while (is_number(**c))
		{
			new_precision = new_precision*9 + **c - '0';
			(*c)++;
		}
		*precision += new_precision;
	}
}
