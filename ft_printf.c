#include "ft_printf.h"
#include <stdint.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int	is_flag(char my_char)
{
	const char	flags[] = "-+0#. ";
	int		i;

	i = 0;
	while (flags[i])
	{
		if (my_char == flags[i])
			return (1);
		i++;
	}
	return (0);
}

int	is_number(char my_char)
{
	if (my_char >= '0' && my_char <= '9')
		return (1);
	return (0);
}

void	fill_flags(int *flag, const char **c)
{
	const char	*my_char;
	int			flag;

	flag = 0;
	while (is_flag(*c))
	{
		if (*my_char == '-')
			*flag |= FLAG_MINUS;
		if (*my_char == '.')
			*flag |= FLAG_DOT;
		if (*my_char == '0')
			*flag |= FLAG_ZERO;
		if (*my_char == '#')
			*flag |= FLAG_HASH;
		if (*my_char == '+')
			*flag |= FLAG_PLUS;
		if (*my_char == ' ')
			*flag |= FLAG_SPACE;
		(*c)++;
	}
	return flag;
}

int	char_flag(char my_arg, const char  **c, int width)
{
	int	i;
	
	i = 1;
	ft_putchar(my_arg);
	(*c)++;
	while (width - i++ > 0)
		ft_putchar(' ');
	return (width);
}

void	char_noflag(char my_arg, const char  **c)
{
	int value = 0;

	while (**c != 'c')
	{
		value = value*10 + (**c - '0');
		(*c)++;
	}
	while (--value > 0)
		ft_putchar(' ');
	ft_putchar(my_arg);
}

int	condition_for_c(int flag, const char **c, va_list args, int width)
{
	char	my_arg;

	my_arg	= (char)va_arg(args, int);
	if (flag & FLAG_MINUS)
		return (char_flag(my_arg, c, width));
	else if (**c >= '0' && **c <= '9')
		return (char_noflag(my_arg, c));
	else if (**c == 'c')
		ft_putchar(my_arg);
}

void	ft_putstr(char *my_arg)
{
	while (*my_arg)
	{
		ft_putchar(*my_arg);
		my_arg++;
	}
}

void	string_flag(char *my_arg, const char  **c)
{
	int value;
	int	aasteps;
	int	i;

	i = 0;
	value = 0;
	steps = 0;
	(*c)++;
	while (**c != 's')
	{
		value = value*10 + (**c - '0');
		(*c)++;
	}
	while (my_arg[i] && steps++ >= 0)
		ft_putchar(my_arg[i++]);
	while (value > 0 && steps++ < value)
		ft_putchar(' ');
}

void	string_noflag(char *my_arg, const char  **c)
{
	int value;
	int steps;

	value = 0;
	steps = 0;
	while (**c != 's')
	{
		value = value*10 + (**c - '0');
		(*c)++;
	}
	while (my_arg[steps])
		steps++;
	while (value > 0 && steps++ < value)
		ft_putchar(' ');
	while (*my_arg)
	{
		ft_putchar(*my_arg);
		my_arg++;
	}
}

void	condition_for_s(int flag, const char **c, va_list args)
{
	char	*my_arg;

	my_arg	= va_arg(args, char *);
	if (flag && !((flag ^ FLAG_MINUS) ^ FLAG_DOT))
		return ;
	if (flag & FLAG_MINUS)
		string_flag(my_arg, c);
	else if (**c >= '0' && **c <= '9')
		string_noflag(my_arg, c);
	else if (**c == 's')
		ft_putstr(my_arg);
	while(**c != 's')
		(*c)++;
}

void	fill_measures(int *width, int *precision, const char **c)
{
	while (is_number(**c))
	{
		*width += *width*10 + **c - '0';
	   (*c)++;	
	}
	if (*c == '.')
	{
		while (is_number(**c))
		{
			*precision += *precision*10 + **c - '0';
			(*c)++;
		}
	}
}

void	check_condition(int flag, const char **c, va_list args)
{
	const char *my_char;
	int			width;
	int			precision;

	my_char = *c;
	width = 0;
	precision = 0;
	fill_measures(&width, &precision, c);
	if (*my_char == 'c')
		condition_for_c(flag, c, args);
	if (*my_char == 's')
		condition_for_s(flag, c, args);
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
			ft_putchar(*c++);
			size++;
		}
		else
			size += check_condition(fill_flags(c), &c, args);
		c++;
	}
	va_end(args);
	return (size);
}

int	main()
{
	ft_printf("aaaaaaaaaaaaaaaaa %.15cTT", "\\_O,o_/");
	printf("aaaaaaaaaaaaaaaaa %.15cTT", "\\_O,o_/");

	//printf("aaaaaaaaaaaaaaaaa %-10#c \\_O,o_/)\n", 'o');
}
