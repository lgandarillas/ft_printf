/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lganda <lgandari@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:58:56 by lganda            #+#    #+#             */
/*   Updated: 2023/10/11 15:19:07 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(char *format, va_list arg)
{
	int		i;

	i = 0;
	if (*format == 'c')
		i += ft_putchar(va_arg(arg, int));
	else if (*format == 's')
		i += ft_putstr(va_arg(arg, char *));
	else if (*format == 'p')
		i += ft_putptr(va_arg(arg, unsigned long long));
	else if (*format == 'd' || *format == 'i')
		i += ft_putnbr(va_arg(arg, int));
	else if (*format == 'u')
		i += ft_putnbr_uns(va_arg(arg, unsigned int));
	else if (*format == 'x' || *format == 'X')
		i += ft_putnbr_hex(va_arg(arg, unsigned int), *format);
	else if (*format == '%')
		i += ft_putchar('%');
	else
		return (0);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		aux;
	va_list	arg;

	if (!str)
		return (-1);
	len = 0;
	va_start(arg, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			aux = ft_format((char *)str, arg);
			if (aux == -1)
				return (-1);
			len += aux;
		}
		else
		{
			if (ft_putchar(*str) == -1)
				return (-1);
			else
				len++;
		}
		str++;
	}
	va_end(arg);
	return (len);
}
