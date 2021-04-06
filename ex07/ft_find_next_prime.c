/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:17:21 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/06 15:25:49 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_is_prime(int nb)
{
	int i;

	i = 2;
	while (i <= nb / 2)
	{
		if (nb % i == 0)
			return (0);
		++i;
	}
	return (nb > 1);
}

int	ft_find_next_prime(int nb)
{
	while (!ft_is_prime(nb))
		++nb;
	return (nb);
}
