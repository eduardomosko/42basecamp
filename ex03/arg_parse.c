/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 02:35:37 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/16 21:04:12 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libgen.h>
#include "ft_hexdump.h"

int				g_file_count;
char			**g_files;
char			*g_program_name;
extern void		(*g_print_line)(char*, size_t);
extern void		(*g_print_filepos)(size_t);

void		get_options(int c, char **args)
{
	int flag;
	int i;

	i = 0;
	flag = 0;
	g_file_count = c;
	while (i < c)
	{
		if (ft_strncmp("-C", args[i], 2) == 0)
		{
			g_print_line = print_file_line_c;
			g_print_filepos = edu_print_filepos_c;
			args[i] = NULL;
		}
		++i;
	}
}

void		get_files_to_read(int c, char **args)
{
	int add_stdin;
	int i;

	i = 0;
	add_stdin = 0;
	g_file_count = 0;
	while (i < c)
		if (args[i++] != NULL)
			++g_file_count;
	if (g_file_count == 0)
	{
		++g_file_count;
		add_stdin = 1;
	}
	if ((g_files = malloc(g_file_count * sizeof(char*))) == NULL)
	{
		show_errno();
		exit(2);
	}
	i = g_file_count;
	while (i && c)
		if (args[--c] != NULL)
			g_files[--i] = args[c];
	if (add_stdin)
		g_files[0] = "-";
}

void		parse_args(int c, char **args)
{
	g_program_name = basename(args[0]);
	get_options(c - 1, args + 1);
	get_files_to_read(c - 1, args + 1);
}
