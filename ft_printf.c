#include "ft_printf.h"
#include <stdint.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

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
			flag |= FLAG_DOT;
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
	int	steps;
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
		*width = *width*10 + **c - '0';
	   (*c)++;	
	}
	if (**c == '.')
	{
		while (is_number(**c))
		{
			*precision = *precision*10 + **c - '0';
			(*c)++;
		}
	}
}

int	check_condition(int flag, const char **c, va_list args)
{
	int			width;
	int			precision;

	width = 0;
	precision = -1;
	fill_measures(&width, &precision, c);
	if (**c == 'c')
		return (condition_for_c(flag, args, width));
	if (**c == 's')
		return (condition_for_s(flag, c, args));

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

int	main()
{
 
	int a = ft_printf("%2c\n", '5');
	int b = ft_printf("%-2c\n", '5');

	int c = printf("%2c\n", '5');
	int d = printf("%-2c\n", '5');

	printf("%d-%d-%d-%d", a, b, c,d);

	//printf("aaaaaaaaaaaaaaaaa %-10#c \\_O,o_/)\n", 'o');
}
