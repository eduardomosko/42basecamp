/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 03:02:09 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/04 15:23:38 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

const char	g_lookup[] = "0123456789abcdef";

void	ft_putstr_non_printable(char *str)
{
	char	buf[3];

	buf[0] = '\\';
	while (*str != '\0')
	{
		if (32 <= *str && *str <= 126)
			write(1, str, 1);
		else
		{
			buf[1] = g_lookup[((unsigned char)*str) / 16];
			buf[2] = g_lookup[((unsigned char)*str) % 16];
			write(1, buf, 3);
		}
		++str;
	}
}
