/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 01:36:25 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/16 22:14:05 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "ft_hexdump.h"

void	buffer_offset(char *buf, size_t bs1, size_t offset)
{
	size_t i;

	i = offset;
	while (i < bs1)
	{
		buf[i - offset] = buf[i];
		i++;
	}
}

void	buffer_copy(char *buf1, char *buf2, size_t s)
{
	size_t i;

	i = 0;
	while (i < s)
	{
		buf1[i] = buf2[i];
		i++;
	}
}

int		buffer_eq(char *buf1, char *buf2, size_t s)
{
	size_t i;

	i = 0;
	while (i < s)
	{
		if (buf1[i] != buf2[i])
			return (0);
		i++;
	}
	return (1);
}
