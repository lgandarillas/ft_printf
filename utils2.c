/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:36:25 by lgandari          #+#    #+#             */
/*   Updated: 2023/10/07 11:37:04 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_hex(unsigned long long int n)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		len += ft_putptr(n / 16);
		len += ft_putptr(n % 16);
	}
	else
		len += write(1, n + '0', 1);
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
