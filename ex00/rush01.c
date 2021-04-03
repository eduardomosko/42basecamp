/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 15:37:31 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/03 19:45:42 by emendes-         ###   ########.fr       */
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
			if ((ypo == 0 && xpo == 0))
				ft_putchar('/');
			else if ((ypo == 0 && xpo == x - 1) || (ypo == y - 1 && xpo == 0))
				ft_putchar('\\');
			else if ((ypo == y - 1 && xpo == x - 1))
				ft_putchar('/');
			else if (ypo == 0 || ypo == y - 1 || xpo == 0 || xpo == x - 1)
				ft_putchar('*');
			else
				ft_putchar(' ');
			++xpo;
		}
		ft_putchar('\n');
		++ypo;
	}
}
