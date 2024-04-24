/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgorin <cgorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:12:27 by cgorin            #+#    #+#             */
/*   Updated: 2024/04/24 17:39:52 by cgorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_isspace(int c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}

int	ft_atoi(const char *str)
{
	unsigned int	res;
	int				sign;

	res = 0;
	sign = 1;
	while (*str != '\0' && (ft_isspace((unsigned int)(*str))))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (res == 2147483648)
			sign = -1;
		res = (res * 10) + (*str - '0');
		str++;
	}
	return (res * sign);
}

/* #include <stdio.h>

int	main(void)
{
	printf("%d \n", ft_atoi("4294967129942942"));
	printf("%d \n", atoi("4294967129942942"));
	printf("%d \n", ft_atoi("2147483648"));
	printf("%d \n", atoi("2147483648"));
} */