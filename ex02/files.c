/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 04:32:40 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/16 22:17:43 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "ft_tail.h"

#define READ_SIZE 1024

extern size_t	g_bytes_to_read;
extern char		*g_bytes_buffer;
extern int		g_file_count;
extern char		**g_files;
extern char		*g_program_name;
char			g_buffer[READ_SIZE];

/*
** Write the file header to stdout
*/

void	show_header(const char *filename, int print_newline)
{
	if (print_newline)
		ft_putstr("\n");
	ft_putstr("==> ");
	if (ft_strcmp("-", filename) == 0)
	{
		ft_putstr("standard input");
	}
	else
	{
		ft_putstr(filename);
	}
	ft_putstr(" <==\n");
}

/*
** Write the last bytes of file fd to stdout
*/

int		tail_fd(int fd)
{
	ssize_t	bytes_read;
	size_t	total_bytes_read;

	if (fd < 0)
	{
		return (1);
	}
	total_bytes_read = 0;
	while ((bytes_read = read(fd, g_buffer, READ_SIZE)) > 0)
	{
		total_bytes_read += bytes_read;
		tail_buffer(g_bytes_buffer, g_bytes_to_read, g_buffer, bytes_read);
	}
	if (total_bytes_read < g_bytes_to_read)
		write(1, g_bytes_buffer + g_bytes_to_read - total_bytes_read,
				total_bytes_read);
	else
		write(1, g_bytes_buffer, g_bytes_to_read);
	return (0);
}

/*
** Opens the file descriptor for filename, or returns 0 for - (stdin)
*/

int		get_fd(const char *filename)
{
	if (ft_strcmp("-", filename) == 0)
	{
		return (0);
	}
	else
	{
		return (open(filename, O_RDONLY));
	}
}

/*
** Closes file descriptor, or does nothing for 0 (stdin)
*/

int		discard_fd(int fd)
{
	if (fd == 0)
	{
		return (0);
	}
	else
	{
		return (close(fd));
	}
}
