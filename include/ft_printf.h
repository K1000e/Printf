/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgorin <cgorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:10:50 by cgorin            #+#    #+#             */
/*   Updated: 2024/05/11 16:51:16 by cgorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

//Fonctions UTILS

void	ft_putchar_fd(char c, int fd);
void	ft_putnbr(int n);
int		ft_putnbr_base(unsigned int n, char *base, int base_len);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(char const *s);

//Fonctions PRINTF

int		ft_printf(const char *format, ...);
int		ft_print_char(char c);
int		ft_print_p(void *ptr);
int		ft_print_s(char *s);
int		ft_print_u_x(unsigned int n, char format);
int		ft_print_i_d_c(int number, char format);

#endif