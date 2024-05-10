/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_i_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgorin <cgorin@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:48:06 by cgorin            #+#    #+#             */
/*   Updated: 2024/05/10 23:49:44 by cgorin           ###   ########.fr       */
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

int	ft_print_i_d(int number)
{
	int	i;

	i = nbrlen(number);
	ft_putnbr_fd(number, 1);
	return (i);
}
