/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 20:00:00 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/16 05:19:46 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_put_front(t_list **begin_list, t_list *list)
{

	if (begin_list == 0)
		return ;
	list->next = *begin_list;
	*begin_list = list;
}

void	ft_list_reverse(t_list **begin_list)
{
	t_list *list;
	t_list *temp;

	if (begin_list == 0)
		return ;
	list = 0;
	while (*begin_list != 0)
	{
		temp = (*begin_list)->next;
		ft_list_put_front(&list, *begin_list);
		*begin_list = temp;
	}
	*begin_list = list;
}
