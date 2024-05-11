/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgorin <cgorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:52:35 by cgorin            #+#    #+#             */
/*   Updated: 2024/05/11 17:12:33 by cgorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_printf_format(const char *format, va_list ap)
{
	int	len;

	len = 0;
	while (*format)
	{
		if (*format == '%' && format++ && ft_strchr("cspdiuxX%", *(format)))
		{
			if (*format == 'i' || *format == 'd' || *format == 'c')
				len += (ft_print_i_d_c(va_arg(ap, int), *format));
			else if (*format == 's')
				len += (ft_print_s(va_arg(ap, char *)));
			else if (*format == 'x' || *format == 'X' || *format == 'u')
				len += (ft_print_u_x(va_arg(ap, unsigned int), *format));
			else if (*format == 'p')
				len += (ft_print_p(va_arg(ap, void *)));
			else if (*format == '%')
				len += (ft_print_char(*format));
		}
		else
			len += (ft_print_char(*format));
		format++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, format);
	len = 0;
	len = ft_printf_format(format, ap);
	va_end(ap);
	return (len);
}
