/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:17:21 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/07 21:45:47 by emendes-         ###   ########.fr       */
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
		if (i == 2)
			++i;
		else
			i += 2;
	}
	return (nb > 1);
}

int			ft_find_next_prime(int nb)
{
	while (!ft_is_prime(nb))
	{
		if (nb % 2 && nb > 2)
			nb += 2;
		else
			++nb;
	}
	return (nb);
}
