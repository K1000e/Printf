
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

int    ft_print_id(const char *format, va_list ap, int i, ...)
{
    if (format[i] == '+' && (format[i + 1] == 'i' || format[i + 1] == 'd'))
    {
        int nb = va_arg(ap, int);
        if (nb > 0)
            ft_putchar('+');
        printf("%i", nb);
        i++;
    }
    else if (format[i]== 'i' || format[i]== 'd')
    {
        int nb = va_arg(ap, int);
        printf("%i", nb);
    }
    i++;
    return i;
}
int    ft_print_cs(const char *format, va_list ap, int i, ...)
{
    if (format[i] == 'c')
    {
        char c = (unsigned char) va_arg(ap, int);
        ft_putchar(c);
    }
    else if (format[i] == 's')
    {
        char *str = va_arg(ap, char *);
        ft_putstr(str);
    }
    i++;
    return i;
}


int    ft_printf_option(const char *format, va_list ap, int i, ...)
{
    if (format[i] == '+' || format[i] == 'i' || format[i] == 'd')
    {
        return ft_print_id(format, ap, i);
    }
    else if (format[i] == 'c' || format[i] == 's')
    {
        return ft_print_cs(format, ap, i);
    }
    else if (format[i] == 'u')
    {
        unsigned int nb = va_arg(ap, unsigned int);
        ft_putnbr(nb);
        i++;
    }
    else
    {
      ft_putchar(format[i]);
	  i++;
    }
    return (i);
}
int    ft_printf(const char *str, ...)
{
    int res;
    va_list ap; 
    int i;

    i = 0;
    va_start(ap, str);
    while (str[i])
    {
        if (str[i] == '%')
        {
            i++;
            i = ft_printf_option(str, ap, i);
        }
        else
        {
            ft_putchar(str[i]);
            i++;
        }
    }

    va_end(ap);
    
    return 0;
}

#include <stdio.h>
int main()
{
    int s = 34;
    ft_printf("\n%d%%\n%s\n%c\n", 56, "Hello World", 'H');
}