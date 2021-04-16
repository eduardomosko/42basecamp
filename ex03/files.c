/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 04:32:40 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/16 21:42:43 by emendes-         ###   ########.fr       */
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
size_t			g_buffer_bytes_read = 0;


void	ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	printed;
	unsigned int	to_print;

	printed = 0;
	while (printed < size)
	{
		to_print = size - printed > 16 ? 16 : size - printed;
		if (buffer_eq(&addr[printed], g_buffer1, to_print) && to_print == READ_SIZE && g_file_pos != 0)
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
}

void	show_file(fd)
{
	ssize_t		bytes_read;

	while ((bytes_read = read(fd, g_buffer + g_buffer_bytes_read, READ_SIZE - g_buffer_bytes_read)) > 0)
	{
		g_buffer_bytes_read += bytes_read;
		if (g_buffer_bytes_read % 16 == 0)
		{
			ft_print_memory(g_buffer, g_buffer_bytes_read);
			g_buffer_bytes_read = 0;
		}
	}
}

void	show_all_files(int c, char **files)
{
	int			shown_any;
	int			fd;
	int			i;

	i = 0;
	shown_any = 0;
	g_buffer_bytes_read = 0;
	while (i < c)
	{
		if ((fd = get_fd(files[i])) == -1)
		{
			show_file_error(files[i++]);
			continue ;
		}
		show_file(fd);
		shown_any = 1;
		discard_fd(fd);
		++i;
	}
	if (shown_any)
	{
		ft_print_memory(g_buffer, g_buffer_bytes_read);
		g_print_filepos(g_file_pos);
		ft_putstr("\n");
	}
}

int		get_fd(const char *filename)
{
	return (open(filename, O_RDONLY));
}

int		discard_fd(int fd)
{
	return (close(fd));
}
