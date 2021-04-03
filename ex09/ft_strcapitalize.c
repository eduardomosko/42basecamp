/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 02:08:52 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/03 18:08:20 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef int t_bool;
#define TRUE  1
#define FALSE 0

char *ft_strcapitalize(char *str)
{
	char *it;
	t_bool should_cap;

	it = str;
	should_cap = TRUE;
	while (*it != '\0')
	{
		if (('z' >= *it && *it >= 'a') || ('Z' >= *it && *it >= 'A') || ('9' >= *it && *it >= '0'))
		{
			if (should_cap && 'a' <= *it && *it <= 'z')
				*it = *it - 'a' + 'A';
			should_cap = FALSE;
		}
		else
		{
			should_cap = TRUE;
		}
		++it;
	}
	return (str);
}
