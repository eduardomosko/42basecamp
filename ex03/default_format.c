/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 21:06:50 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/16 21:28:52 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

extern int		g_file_pos;

const char	g_hex_lookup[] = "0123456789abcdef";

void	(*g_print_line)(char*, size_t) = print_file_line_default;
void	(*g_print_filepos)(size_t) = edu_print_filepos_default;

void	edu_print_byte_hex(char c)
{
	char hex[2];

	hex[0] = g_hex_lookup[((unsigned char)c) / 16];
	hex[1] = g_hex_lookup[((unsigned char)c) % 16];
	write(1, hex, 2);
}

void	edu_print_filepos_c(size_t fp)
{
	char *begin;
	char *end;

	begin = ((char*)&fp) + sizeof(int) - 1;
	end = ((char*)&fp) - 1;
	while (begin != end)
		edu_print_byte_hex(*begin--);
}

void	edu_print_filepos_default(size_t fp)
{
	char *begin;
	char *end;

	begin = ((char*)&fp) + sizeof(int) - 1;
	end = ((char*)&fp) - 1;
	write(1, &g_hex_lookup[((unsigned char)*begin--) % 16], 1);
	while (begin != end)
		edu_print_byte_hex(*begin--);
}

void	edu_print_mem_hex_default(char *mem, unsigned int s)
{
	unsigned int i;

	i = 0;
	while (i < s)
	{
		write(1, " ", 1);
		edu_print_byte_hex(i == s - 1 ? 0 : *(mem + 1));
		edu_print_byte_hex(*mem);
		mem += 2;
		i += 2;
	}
}

void	print_file_line_default(char *addr, size_t to_print)
{
	edu_print_filepos_default(g_file_pos);
	edu_print_mem_hex_default(addr, to_print);
}
