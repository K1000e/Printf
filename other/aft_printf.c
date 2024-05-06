/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aft_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgorin <cgorin@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:52:35 by cgorin            #+#    #+#             */
/*   Updated: 2024/05/05 23:40:38 by cgorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printf_format(const char *format, va_list ap)
{
	int    i;
	int len;
	
	i = -1;
	len = 0;
	while(format [++i])
	{
		if (format [i] == '%' && ft_strchr("cspdiuxX%", format[i+1]))
		{
			i++;
			if (format[i] == 'i' || format[i] == 'd')
				len += (ft_print_i_d(va_arg(ap, int)));
			else if (format[i] == 'c')				//ok
				len += (ft_print_char(va_arg(ap, int)));
			else if (format[i] =='s')				//ok
				len += (ft_print_s(va_arg(ap, char *)));
			else if (format[i] == 'x' || format[i] == 'X')
				len += (ft_print_x(va_arg(ap, unsigned int), format[i]));
			else if (format[i] == 'p')
			    len += (ft_print_p(va_arg(ap, void *)));
			else if (format[i] == '%')				//ok
				len += (ft_print_char(format[i]));
			else if (format[i] == 'u')
				len += (ft_print_u(va_arg(ap, unsigned int)));
		}
		else 
			len += (ft_print_char(format[i]));
	}
	return (len);
}

int	ft_printf(char *str, ...)
{
	va_list ap;
	int len;

	len = 0;
	va_start(ap, str);
	len = ft_printf_format(str, ap);
	va_end(ap);
	return (len); 
}

/* #include <stdlib.h>
#include <stdio.h>
int main()
{
	int *p = malloc (sizeof (int));
	int s = 34;
	printf("printf : %y\n%p\n%c\n%s\n", p, 'H', "Hello World");
	ft_printf("ft_printf : %y\n%p\n%c\n%s\n", p, 'H', "Hello World");
	printf("printf 2 :\n%d\n%u\n", +56, 2147483647);
	ft_printf("ft_printf 2 :\n%p\n%u\n", +56, 2147483647);
	printf("printf 2 : &p = %p\n", p);
	ft_printf("ft_printf 2 : &p = %p\n", p);
} */

