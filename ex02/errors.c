/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 04:30:57 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/15 00:41:33 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "ft_tail.h"

extern char	*g_program_name;

/*
** Shows the error messages formatted properly
*/

void	show_file_error(const char *filename)
{
	char		*strerr;

	ft_putstr(g_program_name);
	ft_putstr(": ");
	ft_putstr(filename);
	ft_putstr(": ");
	strerr = strerror(errno);
	ft_putstr(strerr);
	ft_putstr("\n");
}

void	show_error_nn(const char *message)
{
	ft_putstr(g_program_name);
	ft_putstr(": ");
	ft_putstr(message);
}

void	show_error(const char *message)
{
	show_error_nn(message);
	ft_putstr("\n");
}

void	show_errno(void)
{
	char		*strerr;

	strerr = strerror(errno);
	show_error(strerr);
}
