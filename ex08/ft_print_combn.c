/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 00:23:17 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/01 07:10:48 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_combn(int n)
{
	char	num[9];
	char	max[9];
	char	separator[2];
	int		c;

	c = n - 1;
	while (c >= 0)
	{
		max[c] = '9' - (n - 1) + c;
		num[c] = '0' + c;
		--c;
	}
	c = n - 1;
	write(1, num, n);
	while (c >= 0)
	{
		if (num[c] == max[c])
			--c;
		else if (c != n - 1)
		{
			++c;
			num[c] = num[c - 1];
		}
		++num[c];
		if (c == n - 1 || num[c] == max[c])
		{
			write(1, ", ", 2);
			write(1, num, n);
		}
	}
}
