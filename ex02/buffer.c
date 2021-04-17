/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 01:36:25 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/15 02:06:29 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "ft_tail.h"

void	tail_buffer(char *buf1, size_t bs1, char *buf2, size_t bs2)
{
	size_t i;

	i = 0;
	if (bs2 < bs1)
	{
		buffer_offset(buf1, bs1, bs2);
		buffer_copy(buf1 + bs1 - bs2, buf2, bs2);
	}
	else
	{
		buffer_copy(buf1, buf2 + bs2 - bs1, bs1);
	}
}

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
