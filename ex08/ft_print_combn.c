/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 00:23:17 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/01 07:25:51 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_combn(int n)
{
	char	num[9];
	char	max[9];
	int		c;

	c = -1;
	while (++c < n)
	{
		max[c] = '9' - (n - 1) + c;
		num[c] = '0' + c;
	}
	write(1, num, n);
	while (c >= 0)
	{
		if (num[c] == max[c])
			--c;
		else if (++c != n)
			num[c] = num[c - 1];
		else
			--c;
		if (++num[c] == max[c] || c == n - 1)
		{
			write(1, ", ", 2);
			write(1, num, n);
		}
	}
}
