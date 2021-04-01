/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 20:49:35 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/01 06:00:39 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void)
{
	int		counter;
	char	c;
	char	sep[2];

	counter = 0;
	sep[0] = ',';
	sep[1] = ' ';
	while (counter < 10000)
	{
		c = counter / 1000 + '0';
		write(1, &c, 1);
		c = counter / 100 % 10 + '0';
		write(1, &c, 1);
		write(1, &sep[1], 1);
		c = counter / 10 % 10 + '0';
		write(1, &c, 1);
		c = counter % 10 + '0';
		write(1, &c, 1);
		write(1, &sep, 2);
		++counter;
	}
}
