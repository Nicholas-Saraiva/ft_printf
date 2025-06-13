#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

char	fill_flags(int *flag, char *c)
{
	char	*my_char;

	my_char = c;

	while (*my_char)
	{
		if (*my_char == '+')
			flag |= FLAG_PLUS;

		if (*my_char == ' ' && !(flag & FLAG_PLUS))
			flag |= FLAG_SPACE;
		if (*my_char == '-')
		{
			flag |= FLAG_MINUS;
			while (*my_char && (my_char >= '0' && my_char <= '9'))
				my_char++;
			if (*my_char == '#' || *my_char == '+' || *my_char == ' ' ||*my_char == '-')
				return (NULL);
			continue ;
		}
		if (*my_char == '0' && !(flag & FLAG_MINUS))
			flag |= FLAG_ZERO;
			while (*my_char && (my_char >= '0' && my_char <= '9'))
				my_char++;
			if (*my_char == '#' || *my_char == '+' || *my_char == ' ')
				return (NULL);
			continue ;
		if (*my_char == '.')
			flag |= FLAG_DOT;
			while (*my_char && (my_char >= '0' && my_char <= '9'))
				my_char++;
			if (*my_char == '#' || *my_char == '+' || *my_char == ' ' || *my_char == '.')
				return (NULL);
			continue ;
		if (*my_char == '#')
			flag |= FLAG_HASH;
	}
}

int	ft_printf(const char *fstring, ...)
{
	va_list	args;
	char	*c;
	int		flag;

	va_start(args, fstring);
	c = fstring;
	flag = 0;
	while (*c)
	{
		if(*c != '%')
		{
			putchar(*c);
			c++;
			continue ;
		}
		p++;
		fill_flags(&flag, c, args);
		if (!flag)
		{
			puthcar('%')
			continue ;
		}
	}
	va_end(ap);
}

int	main()
{
	char	ola[] = "BUENO :)";
	int		number	= 3;

	minprintf("HOJE stoy %d dias %s\n", number, ola);
	printf("HOJE estoy %d dias %s", number, ola);
}
