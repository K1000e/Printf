/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgorin <cgorin@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:52:35 by cgorin            #+#    #+#             */
/*   Updated: 2024/05/06 16:24:24 by cgorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_printf_format(const char *format, va_list ap)
{
	int len;

	len = 0;
    if (*format == 'i' || *format == 'd')
	    return (ft_print_i_d(va_arg(ap, int)));
	else if (*format == 'c')
	    return (ft_print_char(va_arg(ap, int)));
	else if (*format =='s')
	    return (ft_print_s(va_arg(ap, char *)));
	else if (*format == 'x' || *format == 'X')
		return (ft_print_x(va_arg(ap, unsigned int), *format));
	else if (*format == 'p')
		return (ft_print_p(va_arg(ap, void *)));
	else if (*format == '%')
		return (ft_print_char(*format));
	//else if (*format == 'u')
//		return (ft_print_u(va_arg(ap, unsigned int)));
	return (len);
}

int    ft_printf(const char *format, ...)
{
	va_list ap;
    int len;

	if (!format)
	    return (0);
    va_start(ap, format);
	len = 0;
 	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (ft_strchr("cspdiuxX", *format))
			{
                len += ft_printf_format(format, ap);
				va_arg(ap, void *);
			}
			else if (*format == '%')
			    len += (ft_print_char('%'));
			else
			{
                //len += (ft_print_char('%'));
                len += (ft_print_char(*format));
            }
		}
		else
			len += (ft_print_char(*format));
		format++;
	}
    va_end(ap);
    return (len);
}
/* #include <stdio.h>

int main(void)
{
	int i;
	int v=0;
	int *ptr;

	ptr = &v;
	i = ft_printf("Minemine: %d\n", 42);
		ft_printf("%i\n", i);
	i = printf("Original : %d\n", 42);
		printf("%i\n", i);
    i = ft_printf("Minemine : %s\n", "42");
		ft_printf("%i\n", i);
	i = printf("Original : %s\n", "42");
		ft_printf("%i\n", i);
    i = ft_printf("Minemine : %c\n", '4');
		ft_printf("%i\n", i);
	i = printf("Original : %c\n", '4');
		ft_printf("%i\n", i);
    i = ft_printf("Minemine : %s\n", "42");
		ft_printf("%i\n", i);
	i = printf("Original : %s\n", "42");
		ft_printf("%i\n", i);
	i = ft_printf("Minemine : %x\n", 42);
		ft_printf("%i\n", i);
	i = printf("Original : %x\n", 42);
		ft_printf("%i\n", i);
	i = ft_printf("Minemine : %X\n", 42);
		ft_printf("%i\n", i);
	i = printf("Original : %X\n", 42);
		ft_printf("%i\n", i);
	i = ft_printf("Minemine : %p\n", ptr);
		ft_printf("%i\n", i);
	i = printf("Original : %p\n", ptr);
		ft_printf("%i\n", i);
	i = ft_printf("Minemine : %z\n");	
		ft_printf("%i\n", i);
	i = printf("Original : %z\n");	
		ft_printf("%i\n", i);
} */