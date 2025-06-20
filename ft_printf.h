/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 04:07:16 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/06/18 16:24:26 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>

# define FLAG_MINUS 1 << 0 // 1
# define FLAG_ZERO 1 << 1 // 2
# define FLAG_DOT 1 << 2 // 4
# define FLAG_HASH 1 << 3 // 8
# define FLAG_SPACE 1 << 4 // 16
# define FLAG_PLUS 1 << 5 // 32

void	ft_putchar(char c);
#endif
