/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 02:40:56 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/13 03:18:36 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#define READ_SIZE 128

char g_buffer[READ_SIZE];

int		show_file(const char *filename)
{
	ssize_t	bytes_read;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		return (1);
	}
	while ((bytes_read = read(fd, g_buffer, READ_SIZE)) != 0)
	{
		write(1, g_buffer, bytes_read);
	}
	close(fd);
	return (0);
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
	{
		if (show_file(argv[1]))
		{
			write(1, "Cannot read file.\n", 18);
			return (1);
		}
	}
	else if (argc > 2)
	{
		write(1, "Too many arguments.\n", 20);
		return (2);
	}
	else
	{
		write(1, "File name missing.\n", 19);
		return (3);
	}
	return (0);
}
