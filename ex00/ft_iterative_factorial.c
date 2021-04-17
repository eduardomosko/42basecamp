/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:57:22 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/05 17:00:42 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int factorial;

	if (nb < 0)
		return (0);
	factorial = 1;
	while (nb > 0)
		factorial *= nb--;
	return (factorial);
}
