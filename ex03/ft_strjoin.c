/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 13:01:48 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/09 20:46:00 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	edu_joined_size(int size, char **strs, char *sep)
{
	unsigned int	total_size;
	unsigned int	offset;
	int				i;

	i = -1;
	offset = 0;
	total_size = 0;
	while (++i < size)
		while (strs[i][offset] != '\0')
			++total_size && ++offset;
	i = 0;
	while (*sep != '\0')
		++sep && ++i;
	return (total_size + ((size - 1) * i) + 1);
}

char			*ft_strjoin(int size, char **strs, char *sep)
{
	unsigned int	offset;
	char			*ret;
	char			*itstr;
	char			*itsep;
	int				i;

	if ((ret = malloc(edu_joined_size(size, strs, sep))) == 0)
		return (0);
	i = -1;
	itstr = ret;
	while (++i < size)
	{
		offset = 0;
		while (strs[i][offset] != '\0')
			*itstr++ = strs[i][offset++];
		if (i != size - 1)
		{
			itsep = sep;
			while (*itsep != '\0')
				*itstr++ = *itsep++;
		}
	}
	*itstr = '\0';
	return (ret);
}
