/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 03:24:15 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/16 09:49:47 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_swap(t_list **n1, t_list **n2)
{
	t_list *temp;

	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
	temp = (*n1)->next;
	(*n1)->next = (*n2)->next;
	(*n2)->next = temp;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list **it;
	t_list *first;

	first = *begin_list;
	while (*begin_list != 0)
	{
		it = &((*begin_list)->next);
		while (*it != 0)
		{
			if (cmp((*it)->data, (*begin_list)->data) < 0)
				ft_list_swap(it, begin_list);
			if (*it)
				it = &((*it)->next);
		}
		if (*begin_list)
			begin_list = &((*begin_list)->next);
	}
}
