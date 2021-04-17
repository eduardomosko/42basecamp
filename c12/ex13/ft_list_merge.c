/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 21:41:08 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/16 05:50:23 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	if (begin_list1 == 0)
		return ;
	while (*begin_list1 != 0)
		begin_list1 = &((*begin_list1)->next);
	*begin_list1 = begin_list2;
}
