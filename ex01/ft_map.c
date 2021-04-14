/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:57:17 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/14 19:18:24 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int *ret;

	if ((ret = malloc(tab * sizeof(int))) == NULL)
		return (NULL);
	while (i < n)
	{
		ret[i] = f(tab[i]);
	}
	return (ret);
}
