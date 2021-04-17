/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   views.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 19:00:15 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/11 20:21:08 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

/*
** Calcula quantas caixas são visíveis em um combinacao
**
** Faz isso checando quantas caixas são maiores que a maior já vista até agora
** partindo da direção definida por view.
*/

int		count_visible(char *comb, t_view view)
{
	int count;
	int max;
	int i;
	int end;
	int dir;

	count = 0;
	max = 0;
	dir = (view == VIEW_UP || view == VIEW_LEFT) ? 1 : -1;
	i = dir > 0 ? 0 : 3;
	end = dir > 0 ? 4 : -1;
	while (i != end)
	{
		if (max < comb[i])
		{
			max = comb[i];
			++count;
		}
		i += dir;
	}
	return (count);
}

/*
** Retorna o requerimento de caixas em uma vista por coluna/linha
*/

int		get_expected_view(const int *views, t_view view, int num)
{
	return (views[view * 4 + num]);
}
