/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lganda <lgandari@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:30:06 by lganda            #+#    #+#             */
/*   Updated: 2023/10/06 18:48:27 by lganda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_putchar(int c)
{
	write(1, &c, 1);
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
}

int	ft_putnbr(int	n)
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
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}
