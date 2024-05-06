/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgorin <cgorin@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 19:12:53 by cgorin            #+#    #+#             */
/*   Updated: 2024/05/06 00:38:48 by cgorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	num_len_hexa(unsigned long n)
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

int	ft_print_p(void *ptr)
{
	unsigned long n;
	
	n = (unsigned long)ptr;
	ft_print_s("0x");
	ft_putnbr_base(n, "0123456789abcdef", 16);
	//i += get_adress(n, base);
	return (num_len_hexa(n) + 2);
}
