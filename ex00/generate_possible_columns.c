/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_possible_columns.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 22:32:19 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/10 01:30:37 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** Calcula quantas caixas são visíveis pela esquerda
**
** Faz isso checando quantas caixas são maiores que a maior já vista até agora
** partindo da esquerda (começo do array) para a direita (final do array)
*/

int visible_left(char *array)
{
	int count;
	int max;
	int i;

	count = 0;
	max = 0;
	i = 0;
	while (i < 4)
	{
		if (max < array[i])
		{
			max = array[i];
			++count;
		}
		++i;
	}
	return (count);
}

/*
** Calcula quantas caixas são visíveis pela direita
**
** Faz isso checando quantas caixas são maiores que a maior já vista até agora
** partindo da direita (final do array) para a esquerda (começo do array)
*/

int visible_right(char *array)
{
	int count;
	int max;
	int i;

	count = 0;
	max = 0;
	i = 3;
	while (i >= 0)
	{
		if (max < array[i])
		{
			max = array[i];
			++count;
		}
		--i;
	}
	return (count);
}

/*
** Verifica se uma posição é valida
**
** Transforma um número em uma posição ('1' vira 0, '2' vira 1 ....) e aumenta 1 à
** posição de um array. Se já tiver alguma coisa lá é pq o número está repetido, então
** a posição é inválida
*/

int validate_position(char *array, int until)
{
	int pos[4];
	int i;

	i = 0;
	while (i < 4)
		pos[i++] = 0;
	i = 0;
	while (i <= until)
	{
		if (pos[(array[i] - '1')]++)
			return (0);
		++i;
	}
	return (1);
}

/*
** Gera todas as combinações possíveis de 4 números que não se repetem e
** mostra na tela quantas caixas seriam vísiveis por cada lado
**
** Faz isso de forma recursiva e valida a cada número se vale a pena gerar
** novas possibilidades
*/

void generate_combinations(char *array, int from)
{
	array[from] = '1';
	while (array[from] <= '4')
	{
		if (from == 3 && validate_position(array, from))
		{
			char left = visible_left(array) + '0';
			char right = visible_right(array) + '0';
			write(1, &left, 1);
			write(1, " ", 1);
			write(1, array, 4);
			write(1, " ", 1);
			write(1, &right, 1);
			write(1, "\n", 1);
		}
		else if (validate_position(array, from))
		{
			generate_combinations(array, from + 1);
		}
		++array[from];
	}
}

int main()
{
	char array[] = "0000";
	generate_combinations(array, 0);
}
