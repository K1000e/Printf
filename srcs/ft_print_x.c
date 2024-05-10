/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgorin <cgorin@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:47:32 by cgorin            #+#    #+#             */
/*   Updated: 2024/05/11 00:16:08 by cgorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print_x(unsigned int n, char format)
{
	int	i;

	i = 0;
	if (format == 'X')
		i = ft_putnbr_base(n, "0123456789ABCDEF", 16);
	else if (format == 'x')
		i = ft_putnbr_base(n, "0123456789abcdef", 16);
	return (i);
}
