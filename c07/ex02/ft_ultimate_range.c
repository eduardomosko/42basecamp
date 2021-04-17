/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 04:47:46 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/12 20:08:34 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	unsigned int	i;

	if (range == NULL)
		return (-1);
	if (min < max)
	{
		*range = malloc((max - min) * sizeof(int));
		if (*range == NULL)
			return (-1);
		i = 0;
		while (min < max)
			(*range)[i++] = min++;
		return (i);
	}
	return (0);
}
