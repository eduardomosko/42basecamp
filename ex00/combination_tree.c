/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combination_tree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:43:21 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/11 19:40:32 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>
#include "rush.h"

/*
** Arvore de combinacoes
**
** Guarda todas as combinacoes possiveis de 4 digitos
** que nao se repetem, organizadas com base em quantas
** caixas se pode ver pela frente e por tras
*/

const char *g_comb11[] = {NULL};
const char *g_comb12[] = {"4123", "4213", NULL};
const char *g_comb13[] = {"4312", "4231", "4132", NULL};
const char *g_comb14[] = {"4321", NULL};

const char *g_comb21[] = {"3214", "3124", NULL};
const char *g_comb22[] = {"2143", "2413", "1423", "3142", "3241", "3412", NULL};
const char *g_comb23[] = {"3421", "2431", "1432", NULL};
const char *g_comb24[] = {NULL};

const char *g_comb31[] = {"2134", "2314", "1324", NULL};
const char *g_comb32[] = {"1243", "1342", "2341", NULL};
const char *g_comb33[] = {NULL};
const char *g_comb34[] = {NULL};

const char *g_comb41[] = {"1234", NULL};
const char *g_comb42[] = {NULL};
const char *g_comb43[] = {NULL};
const char *g_comb44[] = {NULL};

const char **g_combination_tree[] =
{
	g_comb11, g_comb12, g_comb13, g_comb14,
	g_comb21, g_comb22, g_comb23, g_comb24,
	g_comb31, g_comb32, g_comb33, g_comb34,
	g_comb41, g_comb42, g_comb43, g_comb44
};

/*
** Pega uma lista da arvore correspondente a
** quantidade de caixas que devem ser visiveis
** pela esquerda e pela direita
*/

const char	**get_possible_combinations(int view_front, int view_back)
{
	int index_front;
	int index_back;

	index_front = 4 * (view_front - 1);
	index_back = (view_back - 1);
	return (g_combination_tree[index_front + index_back]);
}
