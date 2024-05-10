/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgorin <cgorin@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:41:59 by cgorin            #+#    #+#             */
/*   Updated: 2024/05/11 00:17:49 by cgorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putnbr_base(unsigned int n, char *base, int base_len)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n = -n;
	}
	if (n >= (unsigned int)base_len)
		i += ft_putnbr_base(n / base_len, base, base_len);
	i += ft_print_char((base[n % base_len]));
	return (i);
}
