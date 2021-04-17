/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 19:48:55 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/16 05:01:35 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void*))
{
	t_list *temp;

	while (begin_list != NULL)
	{
		temp = begin_list->next;
		free_fct(begin_list->data);
		free(begin_list);
		begin_list = temp;
	}
}
