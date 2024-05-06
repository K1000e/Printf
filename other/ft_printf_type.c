/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgorin <cgorin@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:47:32 by cgorin            #+#    #+#             */
/*   Updated: 2024/05/05 22:17:12 by cgorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_print_nbr_base(int n, char *base, int base_len)
{
	int i;

	i = 0;
	if (n == -2147483648)
	{
		i += ft_print_char('-');
		i += ft_print_char('2');
		n = 147483648;
	}
	if (n < 0)
	{
		i += ft_print_char('-');
		n = -n;
	}
	if (n >= 10)
		ft_print_nbr_base(n / base_len, base, base_len);
	i += ft_print_char((base[n % base_len]));
	return i;
}

static int get_adress(unsigned long long n, char *base)
{
	int len;
	if (!n)
	    return ft_print_s("(nil)");
	if (n == -1ULL)
	    return ft_print_s("ffffffffffffffff");
	len = 0;
	if (n > 16)
		len += get_adress((n / 16), base);
	len += ft_print_char((*(base + (n  % 16))));
	return len;
}

int	ft_print_p(void *ptr)
{
	int i;
	unsigned long n;
	char *base;
	
	i = 0;
	n = (unsigned long)ptr;
	base = "0123456789abcdef";
	i = ft_print_s("0x");
	i += get_adress(n, base);
	return i;
}
/* int ft_print_x(int n, char format)
{
	int i;

	i = 0;
	if (format == 'X')
		ft_putnbr_base_fd(n, "0123456789ABCDEF", 16, 1);
	else if (format == 'x' || format == 'p')
		ft_putnbr_base_fd(n, "0123456789abcdef", 16, 1);
	i++;
	return i;
} */

 int ft_print_x(int n, char format)
{
	int i;

	i = 0;
	if (format == 'X')
		i = ft_print_nbr_base(n, "0123456789ABCDEF", 16);
	else if (format == 'x')
		i = ft_print_nbr_base(n, "0123456789abcdef", 16);
	return i;
}
	
/* int	ft_print_u(int number, char format)
{
	int i;
	char *n;

	ft_putnbr_unsigned(number, 1);
	i++;
	return i;
}  */

int	ft_putnbr_unsigned(unsigned int n, int fd)
{
	int i = 0;
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
	i++;
	return i;
}


int main(void) 
{
    unsigned long number = 12345;
    int chars_written = ft_putunsigned(number);

    return (0);
}