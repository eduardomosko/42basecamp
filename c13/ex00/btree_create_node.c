/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 23:07:26 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/16 23:10:47 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree *ret;

	ret = malloc(sizeof(*ret));
	if (ret != NULL)
	{
		ret->data = item;
		ret->left = NULL;
		ret->right = NULL;
	}
	return (ret);
}
