/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 19:43:53 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/16 04:41:08 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *temp;

	if (begin_list == 0)
		return ;
	temp = ft_create_elem(data);
	if (temp == 0)
		return ;
	temp->next = *begin_list;
	*begin_list = temp;
}

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list *ret;
	int i;

	i = 0;
	ret = 0;
	while (i < size)
	{
		ft_list_push_front(&ret, strs[i]);
		++i;
	}
	return (ret);
}
