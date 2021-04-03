/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 03:49:15 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/03 13:11:05 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

typedef int	t_bool;

#define TRUE  1
#define FALSE 0

const char	g_hex_lookup[16] = {
	'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e'};

void	edu_print_byte_hex(char c)
{
	char hex[2];

	hex[0] = g_hex_lookup[c / 16];
	hex[1] = g_hex_lookup[c % 16];
	write(1, hex, 2);
}

void	edu_print_ptr(void *ptr)
{
	char			*bytes;
	unsigned int	i;

	i = 0;
	bytes = &ptr;
	while (i < sizeof(ptr))
	{
		edu_print_byte_hex(*bytes++);
		++i;
	}
}

void	edu_print_mem_hex(char *mem, unsigned int s)
{
	unsigned int i;

	i = 0;
	while (i < s)
	{
		edu_print_byte_hex(*mem++);
		++i;
		if (i % 2 != 0)
			write(1, " ", 1);
	}
}

void	edu_safe_print_chars(char *c, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (i < s)
	{
		if (32 <= *c && *c <= 126)
			write(1, c, 1);
		else
			write(1, ".", 1);
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
		write(1, ": ", 1);
		to_print = size - printed > 16 ? 16 : size - printed;
		edu_print_mem_hex(&addr[printed], to_print);
		write(1, " ", 1);
		edu_safe_print_chars(&addr[printed], to_print);
		write(1, "\n", 1);
		printed += to_print;
	}
	return addr;
}
