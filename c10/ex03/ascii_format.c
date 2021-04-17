/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 21:10:03 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/16 21:29:17 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_hexdump.h"

extern int		g_file_pos;

void	edu_print_mem_hex_c(char *mem, unsigned int s)
{
	unsigned int i;

	i = 0;
	while (i < s)
	{
		write(1, "  ", 1 + (i % 8 == 0));
		edu_print_byte_hex(*mem++);
		++i;
	}
}

void	edu_safe_print_chars(char *c, unsigned int s)
{
	unsigned int i;

	i = 0;
	ft_putstr(" |");
	while (i < s)
	{
		if (32 <= *c && *c <= 126)
			write(1, c, 1);
		else
			write(1, ".", 1);
		++c;
		++i;
	}
	ft_putstr("|");
}

void	print_file_line_c(char *addr, size_t to_print)
{
	edu_print_filepos_c(g_file_pos);
	edu_print_mem_hex_c(addr, to_print);
	write(1, "                                                  ",
			(50 - (to_print * 3) - (to_print > 8)));
	edu_safe_print_chars(addr, to_print);
}
