/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 03:27:59 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/12 20:10:35 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int					is_separator(char c, char *charset)
{
	while (*charset != '\0')
		if (*charset++ == c)
			return (1);
	return (0);
}

char				*next_substring(char *str, char *charset)
{
	int	am_in_separator;

	am_in_separator = 0;
	while (*str != '\0')
	{
		if (is_separator(*str, charset))
			am_in_separator = 1;
		else if (am_in_separator)
			return (str);
		++str;
	}
	return (str);
}

static char			*ft_strdup_sep(char *src, char *charset)
{
	char			*dest;
	unsigned int	n;

	n = 0;
	while (src[n] != '\0' && !is_separator(src[n], charset))
		++n;
	dest = malloc(n + 1);
	if (dest != NULL)
	{
		dest[n] = '\0';
		while (n--)
			dest[n] = src[n];
	}
	return (dest);
}

unsigned int		count_substrings(char *str, char *charset)
{
	unsigned int n;

	n = 0;
	if (is_separator(*str, charset))
	{
		str = next_substring(str, charset);
		n = -1;
	}
	while (*str != '\0')
	{
		str = next_substring(str, charset);
		++n;
	}
	return (n);
}

char				**ft_split(char *str, char *charset)
{
	unsigned int	s;
	unsigned int	i;
	char			**ret;

	i = 0;
	s = count_substrings(str, charset);
	ret = malloc((s + 1) * sizeof(char*));
	if (ret == NULL)
		return (NULL);
	if (is_separator(*str, charset))
		str = next_substring(str, charset);
	while (*str != '\0')
	{
		ret[i++] = ft_strdup_sep(str, charset);
		str = next_substring(str, charset);
	}
	ret[s] = NULL;
	return (ret);
}
