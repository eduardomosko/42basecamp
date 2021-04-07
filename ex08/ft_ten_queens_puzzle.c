/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:23:15 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/07 04:05:20 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** Checks if a position attends the condition that
** a queen can't reach another in only one move
*/

int		edu_validate_placement(char *pos)
{
	int i;
	int j;

	i = 0;
	while (i < 10)
	{
		j = i;
		while (++j < 10)
			if (pos[i] == pos[j])
				return (0);
		j = i;
		while (++j < 10)
			if (pos[i] == pos[j] + (j - i))
				return (0);
		j = i;
		while (++j < 10)
			if (pos[i] == pos[j] - (j - i))
				return (0);
		++i;
	}
	return (1);
}

int		edu_ten_queens_puzzle(int from, char *buffer)
{
	int count;

	count = 0;
	buffer[from] = '0';
	while (buffer[from] <= '9')
	{
		if (from < 9)
			count += edu_ten_queens_puzzle(from + 1, buffer);
		else if (edu_validate_placement(buffer))
		{
			++count;
			write(1, buffer, 11);
		}
		++buffer[from];
	}
	return (count);
}

int		ft_ten_queens_puzzle(void)
{
	char ten_queens_buffer[11];

	ten_queens_buffer[10] = '\n';
	return (edu_ten_queens_puzzle(0, ten_queens_buffer));
}
