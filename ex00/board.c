/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 19:12:49 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/11 19:53:14 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>
#include "rush.h"

/*
** Copia uma linha apontada por line para a linha row do
** tabuleiro
*/

void	copy_line(char *board, const char *line, int row)
{
	int n;

	n = -1;
	while (++n < 4)
		board[(n * 2) + (row * 8)] = line[n];
}

/*
** Resolve o tabuleiro para views usando uma implementação
** recursiva de backtracking. Além disso limita as combinacoes
** a serem testadas usando a arvore de possibilidades
*/

int		solve_board(char *board, const int *views, int rowf)
{
	int				view_left;
	int				view_right;
	const char		**lines_to_test;

	view_left = get_expected_view(views, VIEW_LEFT, rowf);
	view_right = get_expected_view(views, VIEW_RIGHT, rowf);
	lines_to_test = get_possible_combinations(view_left, view_right);
	while (*lines_to_test != NULL)
	{
		copy_line(board, *lines_to_test, rowf);
		if (validate_board(board, rowf))
		{
			if (rowf >= 3)
			{
				if (is_solved(board, views))
					return (0);
			}
			else if (solve_board(board, views, rowf + 1) == 0)
			{
				return (0);
			}
		}
		++lines_to_test;
	}
	return (1);
}

/*
** Valida se um tabuleiro não possui números repetidos
** nas colunas. Não é necessário checar as linhas já que
** o uso da árvore de possibilidades garante que não vai
** haver repetição.
*/

int		validate_board(char *board, int until)
{
	int pos[4];
	int index;
	int row;
	int col;

	col = 0;
	while (col < 4)
	{
		row = 0;
		zero_buffer(pos, 4 * sizeof(int));
		while (row <= until)
		{
			index = board[(row * 8) + (col * 2)] - '1';
			if (pos[index]++)
				return (0);
			++row;
		}
		++col;
	}
	return (1);
}

/*
** Verifica se um tabuleiro está resolvendo as condições
** especificadas em views. Não é necessário checar as linhas
** já que o uso da árvore de possíbilidades garante que elas
** vão estar corretas.
*/

int		is_solved(char *board, const int *views)
{
	char	col[4];
	int		vis_down;
	int		vis_up;
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			col[j] = board[(i * 2) + (8 * j)];
			++j;
		}
		vis_up = get_expected_view(views, VIEW_UP, i);
		vis_down = get_expected_view(views, VIEW_DOWN, i);
		if (vis_up != count_visible(col, VIEW_UP))
			return (0);
		if (vis_down != count_visible(col, VIEW_DOWN))
			return (0);
		++i;
	}
	return (1);
}

/*
** Inicializa um tabuleiro com o espaçamento necessário
** para que ele possa ser impresso com um simples `write(1, board, 32)`
*/

void	init_board(char *board)
{
	int i;

	i = -1;
	while (++i < 32)
	{
		if ((i + 1) % 8 == 0)
			board[i] = '\n';
		else
			board[i] = ' ';
	}
}
