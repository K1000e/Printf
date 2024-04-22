/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgorin <cgorin@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:52:35 by cgorin            #+#    #+#             */
/*   Updated: 2024/04/11 01:16:58 by cgorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>


void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n <= 9 || n == 0)
		ft_putchar_fd(n + '0', fd);
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}


int	ft_strlen(char const *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

int	ft_print_id(const char *format, va_list ap, int i, ...)
{
	if (format[i] == '+' && (format[i + 1] == 'i' || format[i + 1] == 'd'))
	{
		int nb = va_arg(ap, int);
		if (nb > 0)
			ft_putchar_fd('+', 1);
		ft_putnbr_fd(nb, 1);
		i++;
	}
	else if (format[i]== 'i' || format[i]== 'd')
	{
		int nb = va_arg(ap, int);
		ft_putnbr_fd(nb, 1);
	}
	i++;
	return i;
}

int	ft_print_cs(const char *format, va_list ap, int i, ...)
{
	if (format[i] == 'c')
	{
		ft_putchar_fd(va_arg(ap, int), 1);
		//unsigned char c = (unsigned char) va_arg(ap, int);
		//ft_putchar_fd(c, 1);
	}
	else if (format[i]== 's')
	{
		char *s = va_arg(ap, char *);
		ft_putstr_fd(s, 1);
	}
	i++;
	return i;
}
void	ft_putnbr_plus(int n)
{
	if (n > 0)
		ft_putchar_fd('+', 1);
	ft_putnbr_fd(n, 1);
}


void	ft_puthexa(int n, int fd, char format)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n <= 9 || n == 0)
		ft_putchar_fd(n + '0', fd);
	if (n > 9 && n <= 15)
	{
		if (format == 'X')
			ft_putchar_fd(n + '7', fd);
		else
			ft_putchar_fd(n + 'W', fd);
	}
	if (n > 15)
	{
		ft_puthexa(n / 16, fd, format);
		ft_puthexa(n % 16, fd, format);
	}
}

int	print(char *string, ...)
{
	va_list ap;
	int i;
	int n;

	va_start(ap, string);
	i = 0;
	while(string[i])
	{
		if (string[i] == '%')
		{
			i++;
			if (string[i] == '+' && (string[i + 1] == 'i' || string[i + 1] == 'd'))
			{
				ft_putnbr_plus(va_arg(ap, int));
				i++;
			}
			else if (string[i]== 'i' || string[i]== 'd')
				ft_putnbr_fd(va_arg(ap, int), 1);
				//i = ft_print_id(string, ap, i);
			else if (string[i] == 'c')
				ft_putchar_fd(va_arg(ap, int), 1);
			else if (string[i]== 's')
				ft_putstr_fd(va_arg(ap, char *), 1);
				//i = ft_print_cs(string, ap, i);
			else if (string[i] == 'u')
				ft_putnbr_fd(va_arg(ap, unsigned int), 1);
			else if (string[i] == 'x' || string[i] == 'X')
				ft_puthexa(va_arg(ap, unsigned int), 1, string[i]);
			else if (string[i] == '%')
				ft_putchar_fd(string[i], 1);
			i++;
		}
		else
		{
			ft_putchar_fd(string[i], 1);
			i++;
		}
	}
	va_end(ap);
	
	return i;
}
int main()
{
	int s = 34;
	printf("printf : %0i\n%c\n%-s\n", -15, 'H', "Hello World");
	print("ft_printf : %+i\n%c\n%s\n", 15, 'H', "Hello World");
	printf("printf 2 :\n%d\n%u\n", +56, -56);
	print("ft_printf 2 :\n%i\n%u\n", +56, -56);
}

/* 
.
The integer portion of the result of a decimal conversion (%i, %d, %u, %f, %g, or %G) 
is formatted with thousands grouping characters using the non-monetary grouping character. 
Some locales, including the POSIX C locale, do not provide non-monetary grouping characters 
for use with this flag.
*/

/*
-
-> The result of the conversion is left-justified within the field. 
The conversion is right-justified if this flag is not specified.
*/

/*
space
-> If the first character of a signed conversion is not a sign 
or if a signed conversion results in no characters, a space is placed before the result. 
If the space and + flags both appear, the space flag is ignored.
*/