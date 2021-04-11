/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdepetri <kdepetri@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 16:12:09 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/11 20:20:52 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rush.h"

/*
** Escreve 0 em `size` bytes a partir de `mem`
*/

void	zero_buffer(void *mem, unsigned int size)
{
	char			*buffer;
	unsigned int	i;

	i = 0;
	buffer = mem;
	while (i < size)
		buffer[i++] = 0;
}

/*
** Lê as views requeridas a partir de uma string.
**
** Retorna 0 no sucesso.
*/

int		read_views(int *views, const char *str)
{
	int		i;

	i = 0;
	while (*str != '\0')
	{
		if (i > 15)
			return (1);
		views[i] = *str - '0';
		if (views[i] < 1 || views[i] > 4)
			return (1);
		++str;
		if (*str == ' ' && i < 15)
			++str;
		++i;
	}
	if (i != 16)
		return (1);
	return (0);
}

/*
** Lê as views passadas em argv para determinar as condições necessárias
** aí usa essas condições para resolver o tabuleiro.
**
** Em sucesso, retorna 0.
** Erro 1: Erro de formatação dos argumentos
** Erro 2: Quantidade de argumentos diferente da esperada
** Erro 3: Tabuleiro sem solução
** Erro -1: Erro lógico do programa
*/

int		run(int argc, char *argv[])
{
	char	board[32];
	int		views[16];

	if (argc == 2)
	{
		if (read_views(views, argv[1]) != 0)
		{
			return (1);
		}
		init_board(board);
		if (solve_board(board, views, 0) == 0)
		{
			write(1, board, 32);
			return (0);
		}
		else
		{
			return (3);
		}
	}
	else
	{
		return (2);
	}
	return (-1);
}

/*
** Usa a função `run()` para rodar a lógica do programa
** e exibe "Error" em caso de erro
*/

int		main(int argc, char *argv[])
{
	int error_code;

	error_code = run(argc, argv);
	if (error_code)
	{
		write(1, "Error\n", 6);
	}
	return (error_code);
}
