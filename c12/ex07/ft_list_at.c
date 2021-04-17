/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 19:55:53 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/16 05:08:34 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int i;

	if (begin_list == 0)
		return (0);
	i = 0;
	while (i < nbr && begin_list != 0)
	{
		++i;
		begin_list = begin_list->next;
	}
	if (i == nbr)
		return (begin_list);
	return (0);
}
