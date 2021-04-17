/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 18:36:15 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/15 19:25:25 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

int			ft_sum(int a, int b);
int			ft_sub(int a, int b);
int			ft_div(int a, int b);
int			ft_mod(int a, int b);
int			ft_mult(int a, int b);
int			ft_invalid_operator(int a, int b);
int			get_op(char *op);
extern int	(*g_operators[])(int, int);

void		ft_putnbr(int nb);
void		ft_putstr(const char *str);
int			ft_strcmp(char *s1, char *s2);
int			ft_atoi(char *str);

#endif
