/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 15:33:00 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/03 17:23:01 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int x_tamanho;
	int y_tamanho;
	int x_pos;
	int y_pos;

	x_tamanho = x;
	y_tamanho = y;
	y_pos = 0;
	while (y_pos < y_tamanho)
	{
		x_pos = 0;
		while (x_pos < x_tamanho)
		{
			if ((y_pos == 0 && x_pos == 0) || (y_pos == y - 1 && x_pos == x - 1))
				ft_putchar('A');
			else if ((y_pos == 0 && x_pos == x - 1) || (y_pos == y - 1 && x_pos == 0))
				ft_putchar('C');
			else if (y_pos == 0 || y_pos == y - 1 || x_pos == 0 || x_pos == x - 1)
				ft_putchar('B');
			else
				ft_putchar(' ');
			++x_pos;
		}
		ft_putchar('\n');
		++y_pos;
	}
}
