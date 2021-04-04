/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 03:02:09 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/04 02:51:16 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

const char	g_lookup[] = "0123456789abcdef";

void	ft_putstr_non_printable(char *str)
{
	char	buf[4];
	int		offset;

	buf[0] = '\\';
	while (*str != '\0')
	{
		if (32 <= *str && *str <= 126)
			write(1, str, 1);
		else
		{
			offset = 0;
			if (*str < 0)
			{
				offset = 1;
				buf[1] = '-';
			}
			buf[1 + offset] = g_lookup[((*str / 16) % 16) * (offset ? -1 : 1)];
			buf[2 + offset] = g_lookup[*str % 16 * (offset ? -1 : 1)];
			write(1, buf, (3 + offset));
		}
		++str;
	}
}
