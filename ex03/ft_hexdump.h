/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 04:33:18 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/16 22:14:14 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

# include <unistd.h>

/*
** Open, show and discard file descriptors
*/

void			show_all_files(int c, char **files);
void			show_stdin(void);

void			edu_print_filepos_c(size_t fp);
void			print_file_line_c(char *addr, size_t to_print);

void			edu_print_filepos_default(size_t fp);
void			print_file_line_default(char *addr, size_t to_print);

void			edu_print_byte_hex(char c);

/*
** Shows adequate error messages
*/

void			show_file_error(const char *filename);
void			show_error(const char *message);
void			show_error_nn(const char *message);
void			show_errno(void);

/*
** String operations
*/

unsigned int	ft_strlen(const char *str);
void			ft_putstr(const char *str);
int				ft_strncmp(const char *s1, const char *s2, unsigned int n);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dest, const char *src);

/*
** Buffer operations
*/

void			buffer_offset(char *buf, size_t bs1, size_t offset);
void			buffer_copy(char *buf1, char *buf2, size_t s);
int				buffer_eq(char *buf1, char *buf2, size_t s);

/*
** Argument parser
*/

void			parse_args(int c, char **args);

extern void		(*g_print_line)(char*, size_t);
extern void		(*g_print_filepos)(size_t);

#endif
