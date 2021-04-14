/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 19:55:53 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/14 19:58:58 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int i;

	if (begin_list == NULL)
		return (NULL);
	i = 0;
	while (i < nbr && begin_list->next != NULL)
	{
		++i;
		begin_list = begin_list->next;
	}
	if (i == nbr)
		return (begin_list);
	return (NULL);
}
