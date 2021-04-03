/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwesley- <jwesley-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 15:47:56 by jwesley-          #+#    #+#             */
/*   Updated: 2021/04/03 16:52:07 by jwesley-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void 	rush(int x, int y)
{
	int i;
	int j;

	i = 0;

	while(i < y)
	{
		j = 0;
		while(j < x)
		{
			if ((i == 0 && j == 0) || (i == y - 1 && j == 0))
				ft_putchar('A');
			else if((i == 0 && j == x -1) || (i == y - 1 && j == x - 1))
				ft_putchar('C');
			else if (i == 0 || i == y - 1)
				ft_putchar('B');
			else if (j == 0 || j == x - 1)
				ft_putchar('B');
			else
				ft_putchar(' ');
			++j;
		}
		ft_putchar('\n');
		i++;
	}
}