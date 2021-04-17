/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 19:15:20 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/11 20:21:30 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

/*
** Gerencia o tabuleiro
*/

int				is_solved(char *board, const int *views);
void			init_board(char *board);
int				validate_board(char *board, int until);
int				solve_board(char *board, const int *views, int rowf);
void			copy_line(char *board, const char *line, int row);

/*
** Acesso rapido a arvore de possibilidades
*/

const char		**get_possible_combinations(int view_front, int view_back);

/*
** Usando views e contagem de visibilidade
*/

typedef enum	e_view
{
	VIEW_UP = 0, VIEW_DOWN = 1, VIEW_LEFT = 2, VIEW_RIGHT = 3
}				t_view;

int				count_visible(char *comb, t_view view);
int				get_expected_view(const int *views, t_view view, int num);

/*
** Utilidades
*/

void			zero_buffer(void *mem, unsigned int size);

#endif
