/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 03:47:03 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/15 03:03:03 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"
#include <stdlib.h>

extern int	g_show_header;
extern int	g_file_count;
extern char	*g_bytes_buffer;
extern char	**g_files;

void		do_global_cleanup(void)
{
	free(g_files);
	free(g_bytes_buffer);
}

/*
** Runs the program logic: shows each file specified on argv
** or mirrors stdin to stdout
*/

int			main(int argc, char *argv[])
{
	int			fd;
	int			i;

	parse_args(argc, argv);
	i = 0;
	while (i < g_file_count)
	{
		if (g_files[i] == NULL)
			continue ;
		fd = get_fd(g_files[i]);
		if (fd == -1)
			show_file_error(g_files[i]);
		else
		{
			if (g_show_header)
				show_header(g_files[i], (i != 0));
			tail_fd(fd);
			discard_fd(fd);
		}
		++i;
	}
	do_global_cleanup();
}
