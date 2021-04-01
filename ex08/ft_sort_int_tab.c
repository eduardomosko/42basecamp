/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:10:27 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/01 16:41:12 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int max_pos;
	int temp;
	int i;

	max_pos = size;
	while (max_pos > 0)
	{
		i = 0;
		while (++i < max_pos)
		{
			if (tab[i - 1] > tab[i])
			{
				temp = tab[i - 1];
				tab[i] = tab[i - 1];
				tab[i - 1] = temp;
			}
		}
		--max_pos;
	}
}
