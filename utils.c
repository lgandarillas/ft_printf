/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lganda <lgandari@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:30:06 by lganda            #+#    #+#             */
/*   Updated: 2023/10/10 19:01:44 by lganda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	len;

	if (!s)
	{
		len = write(1, "(null)", 6);
		return (len);
	}
	len = 0;
	while (*s != '\0')
	{
		write(1, s, 1);
		s++;
		len++;
	}
	return (len);
}

int     ft_putptr(unsigned long long n)
{
        int     len;

        len = 0;
        len += write(1, "0x", 2);
        len += ft_putptr_hex((unsigned long long)n);
        return (len);
}

int     ft_putptr_hex(unsigned long long n)
{
        int     len;

        len = 0;
        if (n >= 16)
        {
                len += ft_putptr_hex(n / 16);
                n = n % 16;
        }
        if (n < 10)
                len += ft_putchar('0' + n);
        else
                len += ft_putchar('a' + (n - 10));
        return (len);
}
