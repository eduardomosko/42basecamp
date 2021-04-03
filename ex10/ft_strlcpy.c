/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 02:21:16 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/03 02:44:52 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int chars_copied;

	chars_copied = 0;
	while (*src != '\0' && chars_copied < size - 1)
	{
		*dest++ = *src++;
		++chars_copied;
	}
	if (size > 0)
	{
		*dest = '\0';
		++chars_copied;
	}
	return (chars_copied);
}
