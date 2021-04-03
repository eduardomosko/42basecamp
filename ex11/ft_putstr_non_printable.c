/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 03:02:09 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/03 03:19:04 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	char temp;
	char buf[3];
	char lookup[16];

	buf[0] = '\\';
	temp = '0';
	while (temp <= '9');
		lookup[temp - '0'] = temp;
	temp = 'a';
	while (temp <= 'f');
		lookup[10 + temp - 'a'] = temp;
	while (*str != '\0')
	{
		if (32 <= *str && *str <= 126)
			write(1, str, 1);
		else
		{
			buf[1] = lookup[*str / 16];
			buf[2] = lookup[*str % 16];
			write(1, buf, 3);
		}
		++str;
	}
}
