/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 16:12:09 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/10 18:33:23 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>
#include <unistd.h>

void	edu_zero_buffer(char *buff, unsigned int s)
{
	unsigned int i;

	i = -1;
	while (++i < s)
		buff[i] = 0;
}

void	edu_fill_buffer(char *buff, unsigned int s, char value)
{
	unsigned int i;

	i = -1;
	while (++i < s)
		buff[i] = value;
}

/*
** Calcula quantas caixas são visíveis pela esquerda
**
** Faz isso checando quantas caixas são maiores que a maior já vista até agora
** partindo da esquerda (começo do array) para a direita (final do array)
*/

int		visible_left(char *array)
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

int		visible_right(char *array)
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

char *a11[] = {NULL};
char *a12[] = {"4123", "4213", NULL};
char *a13[] = {"4312", "4231", "4132",  NULL};
char *a14[] = {"4321", NULL};

char *a21[] = {"3214", "3124", NULL};
char *a22[] = {"2143", "2413", "1423", "3142", "3241", "3421", NULL};
char *a23[] = {"3421", "2431", "1432", NULL};
char *a24[] = {NULL};

char *a31[] = {"2134", "2314", "1324", NULL};
char *a32[] = {"1243", "1342", "2341", NULL};
char *a33[] = {NULL};
char *a34[] = {NULL};

char *a41[] = {"1234", NULL};
char *a42[] = {NULL};
char *a43[] = {NULL};
char *a44[] = {NULL};


char **arr[] = {a11, a12, a13, a14, a21, a22, a23, a24, a31, a32, a33, a34, a41, a42, a43, a44};

int vis(int vis_left, int vis_right)
{
	return (4 * (vis_left - 1) + (vis_right - 1));
}

void	copy_possibilitie(char *solution, int row, char *possibilitie)
{
	int i;

	solution += row * 5;
	i = 0;
	while (i < 4)
	{
		*solution++ = *possibilitie++;
		++i;
	}
}

int validate_solution(char *solution, int until)
{
	int pos[4];
	int index;
	int i;
	int j;

	j = 0;
	while (j < 4)
	{
		i = 0;
		edu_zero_buffer(((char*)pos), 4 * sizeof(int));
		while (i < until + 1)
		{
			index = solution[i * 5 + j] - '1';
			if (pos[index]++)
				return (0);
			++i;
		}
		++j;
	}
	return (1);
}

int	verify_solution(char *solution, int *condicoes)
{
	char col[4];
	int i;
	int j;
	int vis_up;
	int vis_down;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			col[j] = solution[i + 5 * j];
			++j;
		}
		vis_up = condicoes[i];
		vis_down = condicoes[4 + i];

		//printf("vu: %i got %i\t vd: %i got %i\n", vis_up, visible_left(col), vis_down, visible_right(col));
		if (vis_up != visible_left(col))
			return (0);
		if (vis_down != visible_right(col))
			return (0);
		++i;
	}
	return (1);
}

// Condições
//  col1up    col2up    col3up    col4up
//  col1down  col2down  col3down  col4down
//  row1left  row2left  row3left  row4left
// row1right row2right row3right row4right
//
// Solução
// 0000\n
// 0000\n
// 0000\n
// 0000\n

int	find_solution(char *solution, int *condicoes, int rowf)
{
	int ret;
	int vis_left;
	int vis_right;
	char **possibilities;

	//printf("%i  %i\n", (2 * 4) + rowf, (3 * 4) + rowf);
	vis_left = condicoes[(2 * 4) + rowf];
	vis_right = condicoes[(3 * 4) + rowf];

	possibilities = arr[vis(vis_left, vis_right)];

	//printf("%i: vl %i   vr %i    index %i\n", rowf, vis_left, vis_right, vis(vis_left, vis_right));
	while (*possibilities != NULL)
	{
		copy_possibilitie(solution, rowf, *possibilities);
		//edu_fill_buffer(solution + (rowf + 1) * 5, (20 - rowf * 5), '*');
		//solution[4] = '\n';
		//solution[9] = '\n';
		//solution[14] = '\n';
		//solution[19] = '\n';
		//write(1, solution, 20);

		if (validate_solution(solution, rowf))
		{
			//write(1, "V\n\n", 3);
			if (rowf >= 3)
			{
				if (verify_solution(solution, condicoes))
				{
					write(1, solution, 20);
					return (1);
				}
			}
			else
			{
				if ((ret = find_solution(solution, condicoes, rowf + 1)))
					return (ret);
			}
		}
		//write(1, "\n", 1);
		++possibilities;
	}
	if (rowf == 0)
		write(1, "Error\n", 6);
	return (0);
}

int main()
{
	char solution[20];
	edu_fill_buffer(solution, 20, 'i');
	solution[4] = '\n';
	solution[9] = '\n';
	solution[14] = '\n';
	solution[19] = '\n';
	//int condicoes[] = {4, 3, 2, 1, 1, 2, 2, 2, 4, 3, 2, 1, 1, 2, 2, 2};
	int condicoes[] = {1,2,3,2,3,2,1,2,1,3,2,3,2,1,3,2};
	find_solution(solution, condicoes, 0);
}

