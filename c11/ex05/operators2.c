/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 18:35:37 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/15 18:37:50 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int	get_op(char *op)
{
	if (ft_strcmp("+", op) == 0)
		return (0);
	else if (ft_strcmp("-", op) == 0)
		return (1);
	else if (ft_strcmp("*", op) == 0)
		return (2);
	else if (ft_strcmp("/", op) == 0)
		return (3);
	else if (ft_strcmp("%", op) == 0)
		return (4);
	else
		return (5);
}

int	ft_invalid_operator(int a, int b)
{
	return (a - a + b - b);
}

int (*g_operators[])(int, int) = {ft_sum, ft_sub, ft_mult,
	ft_div, ft_mod, ft_invalid_operator};
