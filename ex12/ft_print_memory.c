/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 03:49:15 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/04 15:43:50 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

const char	g_hex_lookup[17] = "0123456789abcdef";

void	edu_print_byte_hex(char c)
{
	char hex[2];

	hex[0] = g_hex_lookup[((unsigned char)c) / 16];
	hex[1] = g_hex_lookup[((unsigned char)c) % 16];
	write(1, hex, 2);
}

void	edu_print_ptr(void *ptr)
{
	char *begin;
	char *end;

	begin = ((char*)&ptr) + sizeof(ptr) - 1;
	end = ((char*)&ptr) - 1;
	while (begin != end)
		edu_print_byte_hex(*begin--);
}

void	edu_print_mem_hex(char *mem, unsigned int s)
{
	unsigned int i;

	i = 0;
	while (i < s)
	{
		if ((i + 1) % 2 != 0)
			write(1, " ", 1);
		edu_print_byte_hex(*mem++);
		++i;
	}
}

void	edu_safe_print_chars(char *c, unsigned int s)
{
	unsigned int i;

	i = 0;
	while (i < s)
	{
		if (32 <= *c && *c <= 126)
			write(1, c, 1);
		else
			write(1, ".", 1);
		++c;
		++i;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	printed;
	unsigned int	to_print;

	printed = 0;
	while (printed < size)
	{
		edu_print_ptr(&addr[printed]);
		write(1, ":", 2);
		to_print = size - printed > 16 ? 16 : size - printed;
		edu_print_mem_hex(&addr[printed], to_print);
		write(1, "                                        ", (41 - (to_print * 2) - (to_print / 2) - (to_print % 2)) );
		edu_safe_print_chars(&addr[printed], to_print);
		write(1, "\n", 1);
		printed += to_print;
	}
	return (addr);
}
//0000000000404567: 0d0a 7072 696e 745f 6d65 6d6f 7279 0a0a ..print_memory..
