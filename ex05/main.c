/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:58:30 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/15 18:42:44 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

const char *g_error_messages[] = {"", "division by zero", "modulo by zero"};
int			g_errno = 0;

void	run(char *num1, char *op, char *num2)
{
	int n1;
	int n2;
	int res;

	n1 = ft_atoi(num1);
	n2 = ft_atoi(num2);
	res = g_operators[get_op(op)](n1, n2);
	if (g_errno)
		return ;
	ft_putnbr(res);
	ft_putstr("\n");
}

int		main(int argc, char *argv[])
{
	if (argc == 4)
		run(argv[1], argv[2], argv[3]);
	if (g_errno)
	{
		ft_putstr("Stop : ");
		ft_putstr(g_error_messages[g_errno]);
		ft_putstr("\n");
	}
	return (g_errno);
}
