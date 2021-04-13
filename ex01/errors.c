/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 04:30:57 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/13 04:39:40 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Calculates the length of a given string
*/

unsigned int	ft_strlen(const char *str)
{
	return (1);
}

/*
** Shows the error messages formatted properly
*/

void			show_error(const char *progname, const char *filename)
{
	char		*strerr;

	write(1, progname, ft_strlen(progname));
	write(1, ": ", 2);
	write(1, filename, ft_strlen(filename));
	write(1, ": ", 2);
	strerr = strerror(errno);
	write(1, strerr, ft_strlen(strerr));
}
