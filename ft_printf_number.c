/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgorin <cgorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:47:32 by cgorin            #+#    #+#             */
/*   Updated: 2024/04/26 11:48:22 by cgorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	ft_put_x_p(int n, char format)
{
	if (format == 'p')
		ft_putstr_fd("0x", 1);
	if (format == 'X')
		ft_putnbr_base_fd(n, "0123456789ABCDEF", 16, 1);
	else if (format == 'x' || format == 'p')
		ft_putnbr_base_fd(n, "0123456789abcdef", 16, 1);
}

static int	ft_print_i_d_u(char *format, int number, int i)
{
	if (format[i] == 'i' || format[i] == 'd')
		ft_putnbr_fd(number, 1);
	if (format[i] == 'u')
		ft_putnbr_unsigned(number, 1);
	i++;
	return (i);
}

static void	ft_putnbr_unsigned(unsigned int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n = -n;
	}
	if (n <= 9 || n == 0)
		ft_putchar_fd(n + '0', 1);
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, 1);
		ft_putnbr_fd(n % 10, 1);
	}
}