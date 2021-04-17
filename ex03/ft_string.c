/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 23:17:20 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/15 02:33:33 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcpy(char *dest, const char *src)
{
	char *ret;

	ret = dest;
	while (*src != '\0')
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return (ret);
}

int		ft_strlen(const char *str)
{
	int n;

	n = 0;
	while (str[n] != 0)
		++n;
	return (n);
}

void	ft_putstr(const char *str)
{
	int n;

	n = 0;
	while (str[n] != '\0')
		++n;
	write(1, str, n);
}

int		ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int i;

	i = 0;
	if (n == 0)
		return (0);
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2 && i < n - 1)
	{
		++s1;
		++s2;
		++i;
	}
	return (((int)(unsigned char)*s1) - ((int)(unsigned char)*s2));
}

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (((int)(unsigned char)*s1) - ((int)(unsigned char)*s2));
}
