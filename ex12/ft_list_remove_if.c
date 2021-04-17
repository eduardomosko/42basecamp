/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:11:52 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/16 09:49:12 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list,
		void *data_ref, int (*cmp)(), void (*free_fct)(void*))
{
	t_list	*temp;

	while (*begin_list != NULL)
	{
		while (cmp((*begin_list)->data, data_ref) == 0)
		{
			temp = (*begin_list)->next;
			free_fct((*begin_list)->data);
			free(*begin_list);
			*begin_list = temp;
		}
		begin_list = &((*begin_list)->next);
	}
}
