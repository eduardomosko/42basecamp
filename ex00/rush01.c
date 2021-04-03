/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 15:37:31 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/03 15:38:00 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if ((i == 0 && j == 0) || (i == y - 1 && j == x - 1))
				ft_putchar('/');
			else if ((i == 0 && j == x - 1) || (i == y - 1 && j == 0))
				ft_putchar('\\');
			else if (i == 0 || i == y - 1 || j == 0 || j == x - 1)
				ft_putchar('*');
			else
				ft_putchar(' ');
			++j;
		}
		ft_putchar('\n');
		++i;
	}
}
