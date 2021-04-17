/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 03:17:35 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/08 04:51:38 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int				*arr;
	unsigned int	i;

	if (min < max)
	{
		arr = malloc((max - min) * sizeof(int));
		i = 0;
		if (arr)
			while (min < max)
				arr[i++] = min++;
		return (arr);
	}
	return (0);
}
