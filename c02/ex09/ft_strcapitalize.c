/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 02:08:52 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/04 15:57:27 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TRUE  1
#define FALSE 0

char	*ft_strcapitalize(char *str)
{
	char	*it;
	int		should_cap;

	it = str;
	should_cap = TRUE;
	while (*it != '\0')
	{
		if (('z' >= *it && *it >= 'a') ||
				('Z' >= *it && *it >= 'A') ||
				('9' >= *it && *it >= '0'))
		{
			if (should_cap && 'a' <= *it && *it <= 'z')
				*it = *it - 'a' + 'A';
			if ((!should_cap) && 'A' <= *it && *it <= 'Z')
				*it = *it - 'A' + 'a';
			should_cap = 0;
		}
		else
		{
			should_cap = 1;
		}
		++it;
	}
	return (str);
}
