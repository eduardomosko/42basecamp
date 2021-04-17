/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 18:36:25 by emendes-          #+#    #+#             */
/*   Updated: 2021/04/15 18:40:58 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (((int)(unsigned char)*s1) - ((int)(unsigned char)*s2));
}

void	ft_putstr(const char *str)
{
	int n;

	n = 0;
	while (str[n] != '\0')
		++n;
	write(1, str, n);
}

void	ft_putnbr(int nb)
{
	char			c;
	unsigned int	div;
	unsigned int	num;

	if (nb < 0)
		write(1, "-", 1);
	num = nb < 0 ? (-1) * nb : nb;
	div = 1;
	while (nb / 10)
	{
		nb = nb / 10;
		div *= 10;
	}
	while (div)
	{
		c = '0' + num / div;
		write(1, &c, 1);
		num = num % div;
		div = div / 10;
	}
}

int		ft_atoi(char *str)
{
	int sign;
	int num;

	while ((9 <= *str && *str <= 15) || *str == ' ')
		++str;
	sign = 1;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		++str;
	}
	num = 0;
	while ('9' >= *str && *str >= '0')
	{
		num *= 10;
		num += sign * (*str - '0');
		++str;
	}
	return (num);
}
