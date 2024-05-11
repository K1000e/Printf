/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_i_d_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgorin <cgorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:48:06 by cgorin            #+#    #+#             */
/*   Updated: 2024/05/11 17:04:57 by cgorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	nbrlen(int n)
{
	int	len;

	len = 0;
	if (n < 1)
		len++;
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_print_char('-');
		ft_print_char('2');
		n = 147483648;
	}
	if (n < 0)
	{
		ft_print_char('-');
		n = -n;
	}
	if (n <= 9 || n == 0)
		ft_print_char(n + '0');
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

int	ft_print_i_d_c(int number, char format)
{
	if (format == 'd' || format == 'i')
	{
		ft_putnbr(number);
		return (nbrlen(number));
	}
	else
		return (ft_print_char(number));
}
