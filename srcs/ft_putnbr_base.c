/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgorin <cgorin@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:41:59 by cgorin            #+#    #+#             */
/*   Updated: 2024/05/06 00:47:22 by cgorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_putnbr_base(unsigned int n, char *base, int base_len)
{
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n = -n;
	}
	if (n >= (unsigned int)base_len)
		ft_putnbr_base(n / base_len, base, base_len);
	ft_putchar_fd((base[n % base_len]), 1);
}

