/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 02:35:37 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/15 03:25:05 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libgen.h>
#include "ft_tail.h"

size_t	g_bytes_to_read;
int		g_file_count;
int		g_show_header;
char	**g_files;
char	*g_program_name;
char	*g_bytes_buffer;

size_t		read_bytes(char *str)
{
	unsigned int	i;
	size_t			num;

	i = 0;
	num = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		num *= 10;
		num += str[i] - '0';
		++i;
	}
	if (str[i] != '\0')
	{
		show_error_nn("invalid number of bytes: ‘");
		ft_putstr(str);
		ft_putstr("’\n");
		exit(1);
	}
	return (num);
}

void		get_bytes_to_read(int c, char **args)
{
	int flag;
	int i;

	i = 0;
	flag = 0;
	g_file_count = c;
	while (i < c)
	{
		if (flag)
		{
			g_bytes_to_read = read_bytes(args[i]);
			args[i] = NULL;
			flag = 0;
		}
		else if (ft_strncmp("-c", args[i], 2) == 0)
		{
			if (args[i][2] != '\0')
				g_bytes_to_read = read_bytes(&(args[i][2]));
			else
				flag = 1;
			args[i] = NULL;
		}
		++i;
	}
	g_bytes_buffer = malloc(g_bytes_to_read);
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
	get_bytes_to_read(c - 1, args + 1);
	get_files_to_read(c - 1, args + 1);
	if (g_file_count > 1)
		g_show_header = 1;
	else
		g_show_header = 0;
}
