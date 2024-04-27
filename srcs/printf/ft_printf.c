/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgorin <cgorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:52:35 by cgorin            #+#    #+#             */
/*   Updated: 2024/04/27 16:27:44 by cgorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/printf.h"

static int	ft_printf_format(char *string, va_list ap)
{
	int i;
	
	i = -1;
	while(string[++i])
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
	}
	return (i);
}

int	ft_printf(char *string, ...)
{
	va_list ap;
	va_start(ap, string);
	int i;

	i = ft_printf_format(string, ap);
	
	va_end(ap);
	return (i);
}

/* #include <stdlib.h>
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
} */

