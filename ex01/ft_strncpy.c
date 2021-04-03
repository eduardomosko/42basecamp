/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 04:27:38 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/03 16:23:05 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = -1;
	while (*src != '\0' && ++i < n)
		dest[i] = *src++;
	while (++i < n)
		dest[i] = '\0';
	return (dest);
}
