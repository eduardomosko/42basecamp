/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdepetri <kdepetri@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 16:12:09 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/11 00:50:15 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <malloc.h>
#include <unistd.h>

/*
** Arvore da vida
*/

const char *g_a11[] = {NULL};
const char *g_a12[] = {"4123", "4213", NULL};
const char *g_a13[] = {"4312", "4231", "4132", NULL};
const char *g_a14[] = {"4321", NULL};

const char *g_a21[] = {"3214", "3124", NULL};
const char *g_a22[] = {"2143", "2413", "1423", "3142", "3241", "3412", NULL};
const char *g_a23[] = {"3421", "2431", "1432", NULL};
const char *g_a24[] = {NULL};

const char *g_a31[] = {"2134", "2314", "1324", NULL};
const char *g_a32[] = {"1243", "1342", "2341", NULL};
const char *g_a33[] = {NULL};
const char *g_a34[] = {NULL};

const char *g_a41[] = {"1234", NULL};
const char *g_a42[] = {NULL};
const char *g_a43[] = {NULL};
const char *g_a44[] = {NULL};

const char **g_tree[] =
{
	g_a11, g_a12, g_a13, g_a14,
	g_a21, g_a22, g_a23, g_a24,
	g_a31, g_a32, g_a33, g_a34,
	g_a41, g_a42, g_a43, g_a44
};

/*
** Calcula quantas caixas são visíveis
**
** Faz isso checando quantas caixas são maiores que a maior já vista até agora
** partindo da direção definida por dir.
*/

int		count_visible(char *array, int dir)
{
	int count;
	int max;
	int i;
	int end;

	count = 0;
	max = 0;
	i = dir > 0 ? 0 : 3;
	end = dir > 0 ? 4 : -1;
	while (i != end)
	{
		if (max < array[i])
		{
			max = array[i];
			++count;
		}
		i += dir;
	}
	return (count);
}

int		validate_board(char *board, int until)
{
	int pos[4];
	int index;
	int row;
	int col;
	int z;

	col = 0;
	while (col < 4)
	{
		row = 0;
		z = -1;
		while (++z < 4)
			pos[z] = 0;
		while (row < until + 1)
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

int		is_solved(char *board, int *condicoes)
{
	char	col[4];
	int		i;
	int		j;
	int		vis_up;
	int		vis_down;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			col[j] = board[(i * 2) + (8 * j)];
			++j;
		}
		vis_up = condicoes[i];
		vis_down = condicoes[4 + i];
		if (vis_up != count_visible(col, 1))
			return (0);
		if (vis_down != count_visible(col, -1))
			return (0);
		++i;
	}
	return (1);
}

/*
** Condições
**  col1up    col2up    col3up    col4up
**  col1down  col2down  col3down  col4down
**  row1left  row2left  row3left  row4left
**  row1right row2right row3right row4right
**
** Solução
**  0 0 0 0\n
**  0 0 0 0\n
**  0 0 0 0\n
**  0 0 0 0\n
*/

int		find_board(char *board, int *condicoes, int rowf)
{
	int				temp;
	int				vis_left;
	int				vis_right;
	const char		**possibilities;

	vis_left = condicoes[(2 * 4) + rowf];
	vis_right = condicoes[(3 * 4) + rowf];
	possibilities = g_tree[(4 * (vis_left - 1) + (vis_right - 1))];
	while (*possibilities != NULL)
	{
		temp = -1;
		while (++temp < 4)
			board[(temp * 2) + (rowf * 8)] = (*possibilities)[temp];
		if (validate_board(board, rowf))
		{
			if (rowf >= 3)
				if (is_solved(board, condicoes))
					return (write(1, board, 32) || 1);
			if (rowf < 3)
				if ((temp = find_board(board, condicoes, rowf + 1)))
					return (temp);
		}
		++possibilities;
	}
	return ((rowf == 0 && write(1, "Error\n", 6)) && 0);
}

int		main(int argc, char *argv[])
{
	char	board[32];
	int		condicoes[16];
	int		i;

	if (argc == 2)
	{
		i = 0;
		while (*argv[1] != '\0')
		{
			condicoes[i] = *(argv[1])++ - '0';
			if (!(1 <= condicoes[i] && condicoes[i] <= 4))
				return (write(1, "Error\n", 6) || 1);
			if (*argv[1] == ' ' && i < 15)
				argv[1]++;
			++i;
		}
		if (i != 16)
			return (write(1, "Error\n", 6) || 1);
		i = -1;
		while (++i < 32)
			board[i] = ((i + 1) % 8 == 0) ? '\n' : ' ';
		find_board(board, condicoes, 0);
	}
	else
		write(1, "Error\n", 6);
}
