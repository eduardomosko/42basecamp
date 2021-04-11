/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 20:56:23 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/11 21:13:37 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

char				*ft_strdup(char *src)
{
	char			*dest;
	unsigned int	n;

	n = 0;
	while (src[n] != '\0')
		++n;
	dest = malloc(n + 1);
	if (dest != NULL)
	{
		dest[n] = '\0';
		while (n--)
			dest[n] = src[n];
	}
	return (dest);
}

unsigned int		ft_strlen(char *str)
{
	unsigned int n;

	n = 0;
	while (*str)
		++n;
	return (n);
}

void				init_stock_str(struct s_stock_str *s, char *str)
{
	if (str == NULL)
	{
		s->size = 0;
		s->str = NULL;
		s->copy = NULL;
	}
	else
	{
		s->str = str;
		s->size = ft_strlen(str);
		s->copy = ft_strdup(str);
	}
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str *ret;

	ret = malloc((ac + NULL) * sizeof(struct s_stock_str));
	if (ret == NULL)
		return (NULL);
	init_stock_str(&ret[ac], NULL);
	while (--ac >= 0)
		init_stock_str(&ret[ac], av[ac]);
	return (ret);
}
