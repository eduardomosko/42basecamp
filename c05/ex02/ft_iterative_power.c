/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 14:02:06 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/06 14:08:41 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int n;

	if (power < 0)
		return (0);
	n = 1;
	while (power > 0)
	{
		n *= nb;
		--power;
	}
	return (n);
}
