/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 03:47:03 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/13 04:37:26 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

const char	*g_default_files[] = {"-"};

/*
** Runs the program logic: shows each file specified on argv
** or mirrors stdin to stdout
*/

int		main(int argc, char *argv[])
{
	const char	**files;
	int			file_count;
	int			fd;
	int			i;

	files = (const char**)argv + 1;
	file_count = argc - 1;
	if (argc == 1)
	{
		files = g_default_files;
		file_count = 1;
	}
	i = 0;
	while (i < file_count)
	{
		fd = get_fd(files[i]);
		if (fd == -1)
			show_error(argv[0], files[i]);
		else
		{
			show_fd(fd);
			discard_fd(fd);
		}
		++i;
	}
}
