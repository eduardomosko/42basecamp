/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 04:32:40 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/16 21:03:49 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "ft_hexdump.h"

#define READ_SIZE 16

extern int		g_file_count;
extern char		**g_files;
extern char		*g_program_name;
int				g_file_pos;
char			g_buffer[READ_SIZE];
char			g_buffer1[16];
int				g_is_repeating = 0;

void			(*g_print_line)(char*, size_t) = print_file_line_default;
void			(*g_print_filepos)(size_t) = edu_print_filepos_default;

/*
** Write the last bytes of file fd to stdout
*/

const char	g_hex_lookup[] = "0123456789abcdef";

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

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	printed;
	unsigned int	to_print;

	printed = 0;
	while (printed < size)
	{
		to_print = size - printed > 16 ? 16 : size - printed;
		if (buffer_eq(&addr[printed], g_buffer1, to_print) && to_print == 16 && g_file_pos != 0)
		{
			if (!g_is_repeating)
				ft_putstr("*\n");
			g_is_repeating = 1;
		}
		else
		{
			g_is_repeating = 0;
			g_print_line(&addr[printed], to_print);
			write(1, "\n", 1);
		}
		buffer_copy(g_buffer1, &addr[printed], to_print);
		printed += to_print;
		g_file_pos += to_print;
	}
	return (addr);
}

int		show_fd(int fd)
{
	size_t total_bytes_read;
	size_t bytes_read;

	total_bytes_read = 0;
	while ((bytes_read = read(fd, g_buffer, READ_SIZE)) > 0)
	{
		total_bytes_read += bytes_read;
		ft_print_memory(g_buffer, bytes_read);
	}
	g_print_filepos(g_file_pos);
	ft_putstr("\n");
	return (0);
}

void	flush_buffer(char *buffer, size_t s)
{
	ft_print_memory(buffer, s);
}

void	show_all_files(int c, char **files)
{
	size_t		buffer_bytes_read;
	ssize_t		bytes_read;
	int			shown_any;
	int			fd;
	int			i;

	i = 0;
	shown_any = 0;
	buffer_bytes_read = 0;
	while (i < c)
	{
		if ((fd = get_fd(files[i])) == -1)
		{
			show_file_error(files[i++]);
			continue ;
		}
		shown_any = 1;
		while ((bytes_read = read(fd, g_buffer + buffer_bytes_read, READ_SIZE - buffer_bytes_read)) > 0)
		{
			buffer_bytes_read += bytes_read;
			if (buffer_bytes_read % 16 == 0)
			{
				flush_buffer(g_buffer, buffer_bytes_read);
				buffer_bytes_read = 0;
			}
		}
		discard_fd(fd);
		++i;
	}
	if (shown_any)
	{
		flush_buffer(g_buffer, buffer_bytes_read);
		g_print_filepos(g_file_pos);
		ft_putstr("\n");
	}
}

/*
** Opens the file descriptor for filename, or returns 0 for - (stdin)
*/

int		get_fd(const char *filename)
{
	return (open(filename, O_RDONLY));
}

/*
** Closes file descriptor, or does nothing for 0 (stdin)
*/

int		discard_fd(int fd)
{
	return (close(fd));
}
