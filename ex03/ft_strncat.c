/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 03:09:42 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/05 03:13:08 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*ret;
	unsigned int	i;

	i = 0;
	ret = dest;
	while (*dest != '\0')
		++dest;
	while (*src != '\0' && i < nb)
	{
		*dest++ = *src++;
		++i;
	}
	return (ret);
}
