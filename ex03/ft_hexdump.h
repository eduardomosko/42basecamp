/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 04:33:18 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/16 21:02:44 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

# include <unistd.h>

/*
** Open, show and discard file descriptors
*/

int				get_fd(const char *filename);
int				discard_fd(int fd);
void			show_header(const char *filename, int print_newline);
int				show_fd(int fd);
void			flush_buffer(char *buffer, size_t s);
void			show_all_files(int c, char **files);

void			edu_print_filepos_c(size_t fp);
void			print_file_line_c(char *addr, size_t to_print);

void			edu_print_filepos_default(size_t fp);
void			print_file_line_default(char *addr, size_t to_print);

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

void			tail_buffer(char *buf1, size_t bs1, char *buf2, size_t bs2);
void			buffer_offset(char *buf, size_t bs1, size_t offset);
void			buffer_copy(char *buf1, char *buf2, size_t s);
int				buffer_eq(char *buf1, char *buf2, size_t s);

/*
** Argument parser
*/

void			parse_args(int c, char **args);

#endif
