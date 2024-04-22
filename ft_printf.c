/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgorin <cgorin@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:15:22 by cgorin            #+#    #+#             */
/*   Updated: 2024/04/10 23:46:49 by cgorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n <= 9 || n == 0)
		ft_putchar(n + '0');
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}
int	ft_strlen(char const *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}
/* int	ft_printf_flags(const char *format, va_list ap, ...)
{
	int i;
	
	i = 0;
	
} */
int	ft_print_id(const char *format, va_list ap, int i, ...)
{
	if (format[i] == '+' && (format[i + 1] == 'i' || format[i + 1] == 'd'))
	{
		printf("Test print id\n");
		int nb = va_arg(ap, int);
		if (nb > 0)
			ft_putchar('+');
		ft_putnbr(nb);
		i++;
	}
	else if (format[i]== 'i' || format[i]== 'd')
	{
		int nb = va_arg(ap, int);
		ft_putnbr(nb);
	}
	i++;
	return i;
}
int	ft_print_cs(const char *format, va_list ap, int i, ...)
{
	//printf("canard\n");
	if (format[i] == 'c')
	{
		//printf("canard\n");
		char c = (unsigned char) va_arg(ap, int);
		printf ("test : %c\n", c);
		ft_putchar(c);
	}
	else if (format[i] == 's')
	{
		printf("canard\n");
		char *str = va_arg(ap, char *);
		printf ("%s", str);
		printf("canard\n");
		ft_putstr(str);
		printf("canard\n");
	}
	i++;
	return i;
}

int	ft_printf_option(int i, const char *format,  va_list ap,  ...)
{
	//i++;
	/* int i;
	
	i = 0; */
	/* while (format[i] != 0)
    {
		if (format[i] == '%')
		{ */
			
			//i++;
	if (format[i] == '+' || format[i] == 'i' || format[i] == 'd')
	{
		return ft_print_id(format, ap, i);
	}
	/* else if (format[i] == 'c' || format[i] == 's')
	{ */
		//return ft_print_cs(format, ap, i);
		if (format[i] == 'c')
	{
		//printf("canard\n");
		char c = (unsigned char) va_arg(ap, int);
		printf ("test : %c\n", c);
		ft_putchar(c);
		i++;
	}
	else if (format[i] == 's')
	{
		//printf("canard\n");
		char *str = va_arg(ap, char *);
		//printf ("%s", str);
		//printf("canard\n");
		ft_putstr(str);
		//printf("canard\n");
		i++;
	}
	//i++;
	//}
	
	else if (format[i] == '%')
	{
		ft_putchar('%');
		i++;
	}
		/* 	else if (format[i] == 'i' || format[i] == 'd')
			{
				int nb = va_arg(ap, int);
				ft_putnbr(nb);
			} */
	else if (format[i] == 'u')
	{
		unsigned int nb = va_arg(ap, unsigned int);
		ft_putnbr(nb);
		i++;
	}
		//}
	else
	{
		ft_putchar(format[i]);
		i++;
	}
	//}
	return (i);
}
int	ft_printf(const char *str, ...)
{
	int res;
	va_list ap; 
	size_t i;
	char *s;

	i = 0;
	va_start(ap, str);
	while (str[i])
    {
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '+' || str[i] == 'i' || str[i] == 'd')
			{
				i = ft_print_id(str, ap, i);
			}
			/* else if (format[i] == 'c' || format[i] == 's')
			{ */
				//return ft_print_cs(format, ap, i);
			if (str[i] == 'c')
			{
				//char c = (unsigned char) ;
				ft_putchar(va_arg(ap, int));
				i++;
			}
			else if (str[i] == 's')
			{
				s = va_arg(ap, char*);
				printf("Test : %i\n", ft_strlen(s));
				printf("Test : %s\n", s);
				ft_putstr(s);
				i++;
			}
			else if (str[i] == '%')
			{
				ft_putchar('%');
				i++;
			}
			else if (str[i] == 'u')
			{
				unsigned int nb = va_arg(ap, unsigned int);
				ft_putnbr(nb);
				i++;
			}
			else
			{
				ft_putchar(str[i]);
				i++;
			}
			//i++;
			//i = ft_printf_option(i, str, ap);
		}
		else
		{
			ft_putchar(str[i]);
			i++;
		}
	}
			//i++;
	//res = ft_printf_option(str, ap);

	va_end(ap);
	
	return res;
}

int main()
{
	int s = 34;
	printf("printf :\n%d%%\n%c\n%s\n", 56, 'H', "Hello World");
	ft_printf("ft_printf :\n%d%%\n%c\n%s\n", 56, 'H', "Hello World");
	printf("printf 2 :\n%d\n%u\n", +56, -56);
	ft_printf("ft_printf 2 :\n%i\n%u\n", +56, -56);
}
/* 	
Zero or more of the following flags:

 #       A `#' character specifying that the value should be printed
	in an ``alternate form''.  For b, c, d, s and u formats, this
   option has no effect.  For the o formats the precision of the
   output string to a zero.  For the x (X) format, a non-zero
   result has the string 0x (0X) prepended to it.  For a, A, e,
   E, f, F, g and G formats, the result will always contain a
   decimal point, even if no digits follow the point (normally,
   a decimal point only appears in the results of those formats
   number is increased to force the first character of the
   if a digit follows the decimal point).  For g and G formats,
   trailing zeros are not removed from the result as they would
   otherwise be;

 -       A minus sign `-' which specifies left adjustment of the
    output in the indicated field;
 +       A `+' character specifying that there should always be a sign
    placed before the number when using signed formats.
 ‘ ’     A space specifying that a blank should be left before a
    positive number for a signed format.  A `+' overrides a space    
	if both are used;
 0       A zero `0' character indicating that zero-padding should be
    used rather than blank-padding.  A `-' overrides a `0' if
    both are used; */

/* Vous devez implémenter la fonction printf() de la libc. Le prototype de ft_printf() devra être :
 int    ft_printf(const char *, ...);
Voici quelques impératifs à respecter :
• Contrairement à la fonction printf() originale, vous ne devez pas gérer de buffer.
• Vous devez gérer les conversions suivantes : cspdiuxX%
• Votre rendu sera comparé à la fonction printf() originale.
• Vous devez utiliser la commande ar pour créer votre bibliothèque.
L’utilisation de la commande libtool est interdite.
• Votre libftprintf.a doit être créé à la racine de votre dépôt.

Vous devez implémenter les conversions suivantes :
• %c Affiche un seul caractère.
• %s Affiche une chaîne de caractères (telle que définie par la convention C). 
• %p L’argument de pointeur void * doit être affiché en hexadécimal.
• %d Affiche un nombre décimal (base 10).
• %i Affiche un entier en base 10.
• %u Affiche un nombre décimal non signé (base 10).
• %x Affiche un nombre en hexadécimal (base 16) avec des lettres minuscules. 
• %X Affiche un nombre en hexadécimal (base 16) avec des lettres majuscules. 
• %% Affiche un signe pourcentage. */