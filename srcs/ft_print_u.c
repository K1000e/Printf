/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgorin <cgorin@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 19:12:53 by cgorin            #+#    #+#             */
/*   Updated: 2024/05/10 23:50:28 by cgorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print_u(unsigned int number)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789";
	if (number >= 10)
		i += ft_print_u(number / 10);
	i += ft_print_char(*(base + (number % 10)));
	return (i);
}
