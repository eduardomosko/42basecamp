/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 19:33:30 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/14 19:35:16 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int i;

	if (begin_list == NULL)
		return (-1);
	i = 0;
	while (begin_list->next != NULL)
	{
		begin_list = begin_list->next;
		++i;
	}
	return (i);
}
