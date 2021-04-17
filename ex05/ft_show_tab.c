/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 21:15:24 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/12 13:45:47 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

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

void	ft_show_tab(struct s_stock_str *par)
{
	if (par == NULL)
		return ;
	while (par->str != 0)
	{
		write(1, par->str, par->size);
		write(1, "\n", 1);
		ft_putnbr(par->size);
		write(1, "\n", 1);
		write(1, par->copy, par->size);
		write(1, "\n", 1);
		++par;
	}
}
