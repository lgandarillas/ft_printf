/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lganda <lgandari@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:58:56 by lganda            #+#    #+#             */
/*   Updated: 2023/10/04 18:33:22 by lganda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(char *format, va_list ap)
{
	int		i;
	va_list	arg;

	i = 0;
	if (*format == 'c')
		i += ft_putchar(va_arg(arg, int));
	else if (*format == 's')
		i += ft_putstr(va_arg(arg, char *));
	else if (*format == 'p')
		i += ft_putptr(va_arg(arg, unsigned long long int);
	else if (*format == 'd' || format == 'i')
		i += ft_putnbr(va_arg(arg, int));
	else if (*format == 'u')
		i += ft_putnbr_uns(va_arg(arg, unsigned int)));
	else if (*format == 'x' || *format == 'X')
		i += ft_puthex(va_arg(arg, unsigned int), *format);
	else if (*format == '%')
		i += ft_putchar('%');
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	va_start(arg, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			i += ft_format((char *)str, arg);
		}
		else
			i += ft_putchar(*str);
		str++;
	}
	va_end(arg);
	return (i);
}
