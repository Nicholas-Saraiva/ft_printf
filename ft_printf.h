/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 04:07:16 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/06/24 01:41:00 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>

# define FLAG_MINUS 1 << 0 // 1
# define FLAG_ZERO 1 << 1 // 2
# define FLAG_DOT 1 << 2 // 4
# define FLAG_HASH 1 << 3 // 8
# define FLAG_SPACE 1 << 4 // 16
# define FLAG_PLUS 1 << 5 // 32

int	ft_putchar(char c);
int	ft_strlen(const char *s);
int	is_flag(char c);
int	is_number(char my_char);
int	fill_flags(const char **c);
int	condition_for_c(int flag, va_list args, int width);
int	condition_for_s(int flag, va_list args, int width, int precision);
int	condition_for_p(int flag, va_list arg, int width);
int	condition_for_d(int flag, va_list arg, int width, int precision);
int	check_condition(int flag, const char **c, va_list args);
int	ft_printf(const char *fstring, ...);
void	fill_measures(int *width, int *precision, const char **c, int *flag);

#endif
