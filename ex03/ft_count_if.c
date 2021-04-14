/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 17:56:11 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/14 17:58:32 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int(*f)(char*))
{
	int n;
	int i;

	if (tab == NULL)
		return (0);
	n = 0;
	i = 0;
	while (i < length)
		if (f(tab[i++]))
			++n;
	return (n);
}
