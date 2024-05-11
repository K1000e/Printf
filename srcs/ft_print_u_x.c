/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgorin <cgorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:47:32 by cgorin            #+#    #+#             */
/*   Updated: 2024/05/11 16:32:12 by cgorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print_u_x(unsigned int n, char format)
{
	int	i;

	i = 0;
	if (format == 'X')
		i = ft_putnbr_base(n, "0123456789ABCDEF", 16);
	else if (format == 'x')
		i = ft_putnbr_base(n, "0123456789abcdef", 16);
	else if (format == 'u')
	    i = ft_putnbr_base(n, "0123456789", 10);
	return (i);
}
