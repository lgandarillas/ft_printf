/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:36:25 by lgandari          #+#    #+#             */
/*   Updated: 2023/10/07 20:07:13 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_hex(unsigned long long n)
{
	int	len;

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

int	ft_putptr(unsigned long long n)
{
	int	len;

	len = 0;
	len += write(1, "0x", 2);
	len += ft_putptr_hex((unsigned long long)n);
	return (len);
}
/*
int	main(void)
{
	unsigned long long ptr1 = 0x12345;
	unsigned long long ptr2 = 0xDEADBEE;

	int	len1 = ft_putptr(ptr1);
	int	len2 = ft_putptr(ptr2);
	ft_printf("\n%p", len1);
	ft_printf("\n%p", len2);
	return (0);
}*/
