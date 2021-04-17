/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 04:33:18 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/13 04:35:06 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CAT_H
# define FT_CAT_H

/*
** Open, show and discard file descriptors
*/

int		get_fd(const char *filename);
int		discard_fd(int fd);
int		show_fd(int fd);

/*
** Shows adequate error messages
*/

void	show_error(const char *progname, const char *filename);

#endif
