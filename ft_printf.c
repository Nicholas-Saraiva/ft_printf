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

int	fill_flags(int *flag, const char *c)
{
	const char	*my_char;

	my_char = c;
	while (is_flag(*my_char))
	{
		if (*my_char == '+')
			*flag |= FLAG_PLUS;
		if (*my_char == ' ' && !(*flag & FLAG_PLUS))
			*flag |= FLAG_SPACE;
		if (*my_char == '-')
		{
			*flag |= FLAG_MINUS;
			my_char++;
			while (*my_char && (*my_char >= '0' && *my_char <= '9'))
				my_char++;
			if (*my_char == '#' || *my_char == '+' || *my_char == ' ' || *my_char == '-')
				return (0);
		}
		if (*my_char == '0' && !(*flag & FLAG_MINUS))
		{

			*flag |= FLAG_ZERO;
			while (*my_char && (*my_char >= '0' && *my_char <= '9'))
				my_char++;
			if (*my_char == '#' || *my_char == '+' || *my_char == ' ')
				return (0);
		}
		if (*my_char == '.')
		{
			*flag |= FLAG_DOT;
			while (*my_char && (*my_char >= '0' && *my_char <= '9'))
				my_char++;
			if (*my_char == '#' || *my_char == '+' || *my_char == ' ' || *my_char == '.')
				return (0);
		}
		if (*my_char == '#')
			*flag |= FLAG_HASH;
	}
	return (1);
}

void	char_flag(char my_arg, const char  **c)
{
	int value = 0;

	ft_putchar(my_arg);
	(*c)++;
	while (**c != 'c')
	{
		value = value*10 + (**c - '0');
		(*c)++;
	}
	while (--value > 0)
		ft_putchar(' ');
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

void	check_condition(int flag, const char **c, va_list args)
{
	char	my_arg;

	my_arg = 0;
	my_arg	= (char)va_arg(args, int);
	if (flag && flag ^ FLAG_MINUS)
		return ;
	if (flag & FLAG_MINUS)
		char_flag(my_arg, c);
	else if (**c >= '0' && **c <= '9')
		char_noflag(my_arg, c);
	else if (**c == 'c')
		ft_putchar(my_arg);
}

int	ft_printf(const char *fstring, ...)
{
	va_list	args;
	const char	*c;
	int		flag;

	va_start(args, fstring);
	c = fstring;
	flag = 0;
	while (*c)
	{
		if(*c != '%')
		{
			ft_putchar(*c);
			c++;
			continue ;
		}
		c++;
		if (!fill_flags(&flag, c))
		{
			return (0);
		}
		check_condition(flag, &c, args);
		c++;
	}
	va_end(args);
	return (1);
}

int	main()
{
	ft_printf("aaaaaaaaaaaaaaaaa %-#10c \\_O,o_/)\n", 'o');
	//printf("aaaaaaaaaaaaaaaaa %-10c \\_O,o_/)\n", 'o');
}
