/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 03:47:03 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/16 19:27:24 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"
#include <stdlib.h>

extern int	g_file_count;
extern char	**g_files;

void		do_global_cleanup(void)
{
	free(g_files);
}

int			main(int argc, char *argv[])
{
	parse_args(argc, argv);
	show_all_files(g_file_count, g_files);
	do_global_cleanup();
}
