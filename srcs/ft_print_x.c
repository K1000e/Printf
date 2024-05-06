/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgorin <cgorin@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:47:32 by cgorin            #+#    #+#             */
/*   Updated: 2024/05/06 00:27:08 by cgorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	num_len_hexa(unsigned int n)
{
	int num_len;

	num_len = 0;
	if (n == 0)
	    return (1);
	while (n != 0)
	{
        num_len++;
        n /= 16;
    }
	return (num_len);
}

int ft_print_x(unsigned int n, char format)
{
	if (format == 'X')
		ft_putnbr_base(n, "0123456789ABCDEF", 16);
	else if (format == 'x')
		ft_putnbr_base(n, "0123456789abcdef", 16);
	return (num_len_hexa(n));
}