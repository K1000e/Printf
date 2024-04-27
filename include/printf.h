/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgorin <cgorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:10:50 by cgorin            #+#    #+#             */
/*   Updated: 2024/04/27 16:27:06 by cgorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

//Fonctions UTILS

void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_base_fd(int n, char *base, int base_len, int fd);
size_t	ft_strlen(char const *s);

//Fonctions PRINTF

int		ft_printf(char *string, ...);
int		ft_print_c_s(int i, char *format, ...);
void	ft_put_x_p(int n, char format);
int		ft_print_i_d_u(char *format, int number, int i);
void	ft_putnbr_unsigned(unsigned int n, int fd);


#endif