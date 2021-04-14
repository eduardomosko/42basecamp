/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 20:00:00 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/14 20:02:36 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list *list;
	t_list *temp;

	if (begin_list == NULL)
		return ;
	list = NULL;
	temp = NULL;
	while (begin_list != NULL)
	{
		temp = begin_list->next;
		begin_list->next = list;
		list = begin_list;
		begin_list = temp;
	}
}
