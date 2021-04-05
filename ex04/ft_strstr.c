/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 03:17:32 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/05 03:32:26 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*itstr;
	char	*itfind;
	char	*ret;

	while (*str != '\0')
	{
		if (*str == *to_find)
		{
			ret = str;
			itstr = str;
			itfind = to_find;
			while (*itstr == *itfind && *itfind != '\0' && *itstr != '\0')
				++itstr && ++itfind;
			if (*itfind == '\0')
				return (ret);
		}
		++str;
	}
	return ((char*)0);
}
