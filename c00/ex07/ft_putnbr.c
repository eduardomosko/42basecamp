/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:55:32 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/01 00:21:08 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	c;
	int		number_started;
	int		div;

	c = '-';
	if (nb < 0)
	{
		write(1, &c, 1);
	}
	div = -1000000000;
	number_started = 0;
	nb = nb > 0 ? -nb : nb;
	while (div)
	{
		c = '0' + nb / div;
		nb = nb % div;
		if (number_started || c != '0' || div == -1)
		{
			write(1, &c, 1);
			number_started = 1;
		}
		div = div / 10;
	}
}
