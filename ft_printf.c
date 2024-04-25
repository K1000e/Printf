/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgorin <cgorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:52:35 by cgorin            #+#    #+#             */
/*   Updated: 2024/04/25 18:13:26 by cgorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
#include <stdarg.h>

static void	ft_putnbr_u(unsigned int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n = -n;
	}
	if (n <= 9 || n == 0)
		ft_putchar_fd(n + '0', 1);
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, 1);
		ft_putnbr_fd(n % 10, 1);
	}
}

static int	ft_print_i_d_u(char *format, int number, int i)
{
	if (format[i] == 'i' || format[i] == 'd')
		ft_putnbr_fd(number, 1);
	if (format[i] == 'u')
		ft_putnbr_u(number, 1);
	i++;
	return (i);
}

static int	ft_print_c_s(int i, char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	
	if (format[i] == 'c')
		ft_putchar_fd(va_arg(ap, int), 1);
	else if (format[i]== 's')
		ft_putstr_fd(va_arg(ap, char *), 1);
	else if (format [i] == '%')
		ft_putchar_fd(format[i], 1);
	i++;
	return (i);
}

void	ft_putnbr_base_fd(int n, char *base, int base_len, int fd)
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
	if (n >= 10)
		ft_putnbr_base_fd(n / base_len, base, base_len, fd);
	ft_putchar_fd((base[n % base_len]), fd);
}

static void	ft_put_x_p(int n, char format)
{
	if (format == 'p')
		ft_putstr_fd("0x", 1);
	if (format == 'X')
		ft_putnbr_base_fd(n, "0123456789ABCDEF", 16, 1);
	else if (format == 'x' || format == 'p')
		ft_putnbr_base_fd(n, "0123456789abcdef", 16, 1);
}

int	ft_printf(char *string, ...)
{
	va_list ap;
	int i;
	va_start(ap, string);

	i = 0;
	while(string[i])
	{
		if (string[i] == '%')
		{
			i++;
			if (string[i]== 'i' || string[i]== 'd' || string[i] == 'u')
				ft_print_i_d_u(string, va_arg(ap, int), i);
			else if (string[i] == 'c')
				ft_print_c_s(i, string, va_arg(ap, int));
			else if (string[i] == '%')
				ft_putchar_fd(string[i], 1);
			else if (string[i]== 's')
				ft_print_c_s(i, string, va_arg(ap, char *));
			else if (string[i] == 'x' || string[i] == 'X' || string[i] == 'p')
				ft_put_x_p(va_arg(ap, unsigned int), string[i]);
			else
				ft_putchar_fd(string[--i], 1);
		}
		else
			ft_putchar_fd(string[i], 1);
		i++;
	}
	va_end(ap);
	return i;
}

#include <stdlib.h>
int main()
{
	int *p = malloc (sizeof (int));
	int s = 34;
	printf("printf : %y\n%i\n%c\n%s\n", 75, 'H', "Hello World");
	ft_printf("ft_printf : %y\n%i\n%c\n%s\n", 75, 'H', "Hello World");
	printf("printf 2 :\n%d\n%u\n", +56, 2147483647);
	ft_printf("ft_printf 2 :\n%i\n%u\n", +56, 2147483647);
	printf("printf 2 : &p = %p\n", p);
	ft_printf("ft_printf 2 : &p = %p\n", p);
}

