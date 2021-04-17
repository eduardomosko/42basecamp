/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:59:41 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/14 19:18:33 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char*))
{
	if (tab == 0)
		return (0);
	while (*tab != 0)
		if (f(*tab++))
			return (1);
	return (0);
}