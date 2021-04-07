/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 21:17:39 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/07 21:48:12 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	edu_zero_buffer(char *buff, unsigned int s)
{
	unsigned int i;

	i = -1;
	while (++i < s)
		buff[i] = 0;
}

/*
** Checks if a position attends the condition that
** a queen can't reach another in only one move
*/

int		edu_validate_placement(char *pos)
{
	char	buff[19];
	int		i;

	edu_zero_buffer(buff, 19);
	i = -1;
	while (++i < 10)
		if (buff[pos[i] - '0']++)
			return (0);
	edu_zero_buffer(buff, 19);
	i = -1;
	while (++i < 10)
		if (buff[(pos[i] - '0') - i + 9]++)
			return (0);
	edu_zero_buffer(buff, 19);
	i = -1;
	while (++i < 10)
		if (buff[(pos[i] - '0') + i]++)
			return (0);
	return (1);
}

int		edu_ten_queens_puzzle(int from, char fpos, char lpos, char *buffer)
{
	int count;

	count = 0;
	buffer[from] = fpos;
	while (buffer[from] <= lpos)
	{
		if (from < 9)
		{
			count += edu_ten_queens_puzzle(
					from + 1, '0', buffer[from] - 2, buffer);
			count += edu_ten_queens_puzzle(
					from + 1, buffer[from] + 2, '9', buffer);
		}
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
	return (edu_ten_queens_puzzle(0, '0', '9', ten_queens_buffer));
}
