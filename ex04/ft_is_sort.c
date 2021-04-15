/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 18:48:12 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/15 22:37:37 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int dir;
	int res;

	i = 0;
	dir = 0;
	while (i < length - 1)
	{
		res = f(tab[i], tab[i + 1]);
		if (dir == 0 && res != 0)
		{
			if (res < 0)
				dir = -1;
			else
				dir = 1;
		}
		if (dir * res < 0)
			return (0);
		++i;
	}
	return (1);
}
