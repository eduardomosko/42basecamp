/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 02:08:52 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/03 02:09:08 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef int t_bool;
#define TRUE (1==1)
#define FALSE (1==0)

char *ft_strcapitalize(char *str)
{
	char *it;
	t_bool should_cap;

	it = str;
	should_cap = TRUE;
	while (*it != '\0')
	{
		if (!(('z' >= *str && *str == 'a') || ('Z' >= *str && *str >= 'A') || ('9' >= *str && *str >= '0')))
		{
			if (should_cap && 'a' <= *it && *it <= 'z')
				*it = *it - 'A' + 'a';
			should_cap = FALSE;
		}
		else
		{
			should_cap = TRUE
		}
	}
	return (str);
}
