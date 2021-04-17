/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 02:21:16 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/03 23:26:14 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int chars_copied;

	chars_copied = 0;
	while (*src != '\0' && chars_copied < size)
	{
		*dest++ = *src++;
		++chars_copied;
	}
	if (chars_copied == size)
		--dest;
	*dest = '\0';
	while (*src != '\0')
	{
		++chars_copied;
		++src;
	}
	return (chars_copied);
}
