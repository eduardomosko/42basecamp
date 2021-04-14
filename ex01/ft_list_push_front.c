/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 19:28:47 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/14 19:31:37 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *temp;

	if (begin_list == NULL)
		return ;
	temp = malloc(sizeof(t_list));
	if (temp == NULL)
		return ;
	temp->data = data;
	temp->next = *begin_list;
	*begin_list = temp;
}
