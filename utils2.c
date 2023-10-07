/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:36:25 by lgandari          #+#    #+#             */
/*   Updated: 2023/10/07 13:22:04 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_hex(unsigned long long int n)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		len += ft_putptr_hex(n / 16);
		len += ft_putptr_hex(n % 16);
	}
	else
	{
		if (n < 10)
			len += ft_putchar('0' + n);
		else
			len += ft_putchar('a' + (n - 10));
	}
	return (len);
}

int	ft_putptr(unsigned long long int n)
{
	int	len;

	len = 0;
	len += write(1, "0x", 2);
	len += ft_putptr_hex(n);
	return (len);
}
/*
int	main(void)
{
	int	a;
	int	*b;

	a = 5;
	b = &a;
	ft_putptr(b);
	return (0);
}*/
