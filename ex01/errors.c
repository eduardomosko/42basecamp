/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 04:30:57 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/14 23:13:16 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>

/*
** Calculates the length of a given string
*/

unsigned int	ft_strlen(const char *str)
{
	unsigned int n;

	n = 0;
	while (str[n] != '\0')
		++n;
	return (n);
}

/*
** Shows the error messages formatted properly
*/

void			show_error(char *progname, const char *filename)
{
	char		*strerr;
	char		*prog;

	prog = basename(progname);
	write(1, prog, ft_strlen(prog));
	write(1, ": ", 2);
	write(1, filename, ft_strlen(filename));
	write(1, ": ", 2);
	strerr = strerror(errno);
	write(1, strerr, ft_strlen(strerr));
	write(1, "\n ", 1);
}
