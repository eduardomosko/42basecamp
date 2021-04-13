/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 04:32:40 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/13 04:39:16 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#define READ_SIZE 1024

char		g_buffer[READ_SIZE];

/*
** Write the contents of file fd to stdout
*/

int		show_fd(int fd)
{
	ssize_t	bytes_read;

	if (fd < 0)
	{
		return (1);
	}
	while ((bytes_read = read(fd, g_buffer, READ_SIZE)) != 0)
	{
		write(1, g_buffer, bytes_read);
	}
	return (0);
}

/*
** Opens the file descriptor for filename, or returns 0 for - (stdin)
*/

int		get_fd(const char *filename)
{
	if (filename[0] == '-' && filename[1] == '\0')
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
