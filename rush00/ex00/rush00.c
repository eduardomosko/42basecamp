/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwesley- <jwesley-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:28:46 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/03 18:25:20 by jwesley-         ###   ########.fr       */
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
			if ((ypo == 0 || ypo == y - 1) && (xpo == 0 || xpo == x - 1))
				ft_putchar('o');
			else if (ypo == 0 || ypo == y - 1)
				ft_putchar('-');
			else if (xpo == 0 || xpo == x - 1)
				ft_putchar('|');
			else
				ft_putchar(' ');
			++xpo;
		}
		ft_putchar('\n');
		++ypo;
	}
}
