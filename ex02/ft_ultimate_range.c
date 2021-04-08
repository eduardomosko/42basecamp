/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 04:47:46 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/08 05:02:40 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

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
