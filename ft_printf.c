/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lganda <lgandari@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:58:56 by lganda            #+#    #+#             */
/*   Updated: 2023/10/03 14:12:38 by lganda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_ap(va_list ap, const char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(ap, int)));
	if (forat == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (format == 'p')
		return (ft_putptr(va_arg(ap, unsigned long long), 0, 0, 0));
	if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(ap, int), 0, 0, 0));
	if (format == 'u')
		return (ft_putnsbr(va_arg(ap, unsigned int)));
	if (format == 'x')
		return (ft_puthex(va_arg(ap, int), 0, 0, 97));
	if (format == 'X')
		return (ft_puthex(va_arg(ap, int), 0, 0, 65));
	if (format == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	int	i;
	int	len;
	int	aux;

	if (!str)
		return (-1);
	i = 0;
	len = 0;
	aux = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			aux = ft_printf_ap(ap, str[++i]);
		else
			aux = ft_putchar(str[i]);
		if (aux == -1)
			return (-1);
		len += aux;
		i++;
	}
	va_end(ap);
	return (len);
}
