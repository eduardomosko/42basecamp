/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:55:32 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/05 07:42:54 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char			c;
	unsigned int	div;
	unsigned int	num;

	if (nb < 0)
		write(1, "-", 1);
	num = nb < 0 ? (-1) * nb : nb;
	div = 1;
	while (nb / 10)
	{
		nb = nb / 10;
		div *= 10;
	}
	while (div)
	{
		c = '0' + num / div;
		write(1, &c, 1);
		num = num % div;
		div = div / 10;
	}
}
