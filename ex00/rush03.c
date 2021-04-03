/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwesley- <jwesley-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 15:47:56 by jwesley-          #+#    #+#             */
/*   Updated: 2021/04/03 19:57:00 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int xpo;
	int ypo;

	ypo = 0;
	while (ypo < y)
	{
		xpo = 0;
		while (xpo < x)
		{
			if ((ypo == 0 && xpo == 0) || (ypo == y - 1 && xpo == 0))
				ft_putchar('A');
			else if ((ypo == 0 && xpo == x - 1) ||
						(ypo == y - 1 && xpo == x - 1))
				ft_putchar('C');
			else if (ypo == 0 || ypo == y - 1)
				ft_putchar('B');
			else if (xpo == 0 || xpo == x - 1)
				ft_putchar('B');
			else
				ft_putchar(' ');
			++xpo;
		}
		ft_putchar('\n');
		ypo++;
	}
}
