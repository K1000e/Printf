/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgorin <cgorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:38:21 by cgorin            #+#    #+#             */
/*   Updated: 2024/05/11 17:11:43 by cgorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putnbr_base(unsigned int n, char *base, int base_len)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i += ft_print_char('-');
		n = -n;
	}
	if (n >= (unsigned int)base_len)
		i += ft_putnbr_base(n / base_len, base, base_len);
	i += ft_print_char((base[n % base_len]));
	return (i);
}

int	ft_print_s(char *s)
{
	if (s == NULL)
	{
		ft_print_s("(null)");
		return (6);
	}
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}

int	ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_strlen(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)(s));
	return (NULL);
}

