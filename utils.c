/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lganda <lgandari@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:30:06 by lganda            #+#    #+#             */
/*   Updated: 2023/10/07 00:48:05 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char	*s)
{
	int	n;

	n = 0;
	while (*s != '\0')
	{
		write(1, s, 1);
		s++;
		n++;
	}
	return (n);
}

int	ft_putnbr(int n)
{
	int		len;
	int		aux;
	unsigned int	nbr;

	len = 0;
	aux = 0;
	if (n < 0)
	{
		len += write(1, "-", 1);
		nbr = n * -1;
	}
	else
		nbr = n;
	if (n > 9)
		len += ft_putnbr(nbr / 10);
	aux = (nbr % 10);
	len += ft_putchar(aux + '0');
	return (len);
}

int	ft_putnbr_uns(unsigned int n)
{
	int		len;
	int		aux;

	len = 0;
	if (n >= 10)
		len += ft_putnbr_uns(n / 10);
	aux = (n % 10);
	len += ft_putchar(aux + '0');
	return (len);
}
